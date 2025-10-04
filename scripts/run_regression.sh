#!/usr/bin/env bash
set -euo pipefail

# Simple regression runner for riscv-tests/isa programs.
# Usage:
#   scripts/run_regression.sh [--limit N] [--pattern PAT]
#
# Options:
#   --limit N      Run only the first N tests after sorting alphabetically.
#   --pattern PAT  Run only tests whose name (before .dump) matches PAT (grep style).
#
# The script converts each *.dump to a *.hex image, runs `make`, and records the
# PASS/FAIL/UNDEFINED banner from results/<test>-result.txt. A summary table is
# printed at the end, and a non-zero exit code is returned if any test fails or
# produces an UNDEFINED banner.

SCRIPT_DIR=$(cd -- "$(dirname "${BASH_SOURCE[0]}")" && pwd)
REPO_ROOT=$(cd -- "${SCRIPT_DIR}/.." && pwd)
ISA_DIR="${REPO_ROOT}/riscv-tests/isa"
RESULTS_DIR="${REPO_ROOT}/results"
INSTR_DIR="${REPO_ROOT}/instructions"
TEST_FILE="${REPO_ROOT}/.test"

limit=""
pattern=""

while [[ $# -gt 0 ]]; do
    case "$1" in
        --limit)
            [[ $# -ge 2 ]] || { echo "error: --limit requires a value" >&2; exit 1; }
            limit="$2"
            shift 2
            ;;
        --pattern)
            [[ $# -ge 2 ]] || { echo "error: --pattern requires a value" >&2; exit 1; }
            pattern="$2"
            shift 2
            ;;
        -h|--help)
            sed -n '1,25p' "$0"
            exit 0
            ;;
        *)
            echo "Unknown argument: $1" >&2
            exit 1
            ;;
    esac
done

if [[ ! -d "$ISA_DIR" ]]; then
    echo "error: riscv-tests submodule not found at $ISA_DIR" >&2
    exit 1
fi

mapfile -t dumps < <(find "$ISA_DIR" -type f -name '*.dump' | sort)
if [[ ${#dumps[@]} -eq 0 ]]; then
    echo "error: no .dump files found under $ISA_DIR" >&2
    exit 1
fi

# Apply optional pattern filter.
if [[ -n "$pattern" ]]; then
    filtered=()
    for dump in "${dumps[@]}"; do
        name=$(basename "$dump" .dump)
        if [[ "$name" =~ $pattern ]]; then
            filtered+=("$dump")
        fi
    done
    if [[ ${#filtered[@]} -gt 0 ]]; then
        dumps=("${filtered[@]}")
    else
        dumps=()
    fi
fi

if [[ ${#dumps[@]} -eq 0 ]]; then
    echo "error: no tests matched the requested filter" >&2
    exit 1
fi

if [[ -n "$limit" ]]; then
    if ! [[ "$limit" =~ ^[0-9]+$ ]]; then
        echo "error: --limit expects an integer" >&2
        exit 1
    fi
    dumps=("${dumps[@]:0:$limit}")
fi

declare -A counts=([PASS]=0 [FAIL]=0 [UNDEFINED]=0 [ERROR]=0)
results_summary=()

pushd "$REPO_ROOT" >/dev/null

# Ensure output directories exist.
mkdir -p "$RESULTS_DIR" "$INSTR_DIR"

for dump in "${dumps[@]}"; do
    test_name=$(basename "$dump" .dump)
    printf '\n=== Running %s ===\n' "$test_name"

    hex_path="$INSTR_DIR/$test_name.hex"

    if ! python3 "$REPO_ROOT/test/converter.py" "$dump" "$hex_path"; then
        echo "converter failed for $test_name" >&2
        counts[ERROR]=$((counts[ERROR] + 1))
        results_summary+=("$test_name ERROR converter")
        continue
    fi

    echo "$test_name" > "$TEST_FILE"

    tmp_log=$(mktemp)
    if ! make -s >"$tmp_log" 2>&1; then
        echo "make failed for $test_name" >&2
        cat "$tmp_log" >&2
        rm -f "$tmp_log"
        counts[ERROR]=$((counts[ERROR] + 1))
        results_summary+=("$test_name ERROR build")
        continue
    fi
    rm -f "$tmp_log"

    result_file="$RESULTS_DIR/${test_name}-result.txt"
    if [[ ! -f "$result_file" ]]; then
        echo "missing result file for $test_name" >&2
        counts[ERROR]=$((counts[ERROR] + 1))
        results_summary+=("$test_name ERROR missing-result")
        continue
    fi

    banner=$(grep -E 'PASS|FAIL|UNDEFINED' "$result_file" | tail -n 1 || true)
    status="UNDEFINED"
    if [[ "$banner" =~ PASS ]]; then
        status=PASS
    elif [[ "$banner" =~ FAIL ]]; then
        status=FAIL
    elif [[ -z "$banner" ]]; then
        status=ERROR
    fi

    counts[$status]=$((counts[$status] + 1))
    results_summary+=("$test_name $status")
    printf 'Result: %s\n' "$status"
    if [[ "$status" == FAIL || "$status" == UNDEFINED ]]; then
        echo "  (see $result_file)"
    fi
done

popd >/dev/null

printf '\n=== Regression summary ===\n'
for entry in "${results_summary[@]}"; do
    printf '%s\n' "$entry"
done
printf '\nPASS: %d\nFAIL: %d\nUNDEFINED: %d\nERROR: %d\n' \
    "${counts[PASS]}" "${counts[FAIL]}" "${counts[UNDEFINED]}" "${counts[ERROR]}"

if (( counts[FAIL] > 0 || counts[UNDEFINED] > 0 || counts[ERROR] > 0 )); then
    exit 1
fi

exit 0
