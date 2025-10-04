#!/usr/bin/env python3
"""Summarize regression results into Markdown or CSV tables."""

from __future__ import annotations

import argparse
import csv
import sys
from pathlib import Path
from typing import Iterable, List, Tuple

PASS_TOKENS = {"PASS", "FAIL"}
CYCLE_PREFIX = "Simulation complete. Total cycles: "
UNDEFINED_PREFIX = "UNDEFINED value"

def parse_result_file(path: Path) -> Tuple[str, str, int | None, List[str]]:
    status = "UNDEFINED"
    cycles = None
    notes: List[str] = []

    with path.open("r", encoding="utf-8", errors="ignore") as fh:
        for raw_line in fh:
            line = raw_line.strip()
            if not line:
                continue
            if line in PASS_TOKENS:
                status = line
            elif line.startswith("UNDEFINED") and line not in PASS_TOKENS:
                if UNDEFINED_PREFIX not in notes:
                    notes.append(UNDEFINED_PREFIX)
            if line.startswith(CYCLE_PREFIX):
                try:
                    cycles = int(line[len(CYCLE_PREFIX) :])
                except ValueError:
                    pass
    return (path.stem.replace("-result", ""), status, cycles, notes)

def iter_results(results_dir: Path) -> Iterable[Tuple[str, str, int | None, List[str]]]:
    for result_path in sorted(results_dir.glob("*-result.txt")):
        yield parse_result_file(result_path)

def emit_markdown(rows: Iterable[Tuple[str, str, int | None, List[str]]]) -> None:
    print("| Test | Status | Cycles | Notes |")
    print("|------|--------|--------|-------|")
    for test, status, cycles, notes in rows:
        cycle_text = str(cycles) if cycles is not None else "—"
        notes_text = ", ".join(notes) if notes else ""
        print(f"| `{test}` | {status} | {cycle_text} | {notes_text} |")

def emit_csv(rows: Iterable[Tuple[str, str, int | None, List[str]]], out_file: Path | None) -> None:
    target = sys.stdout if out_file is None else out_file.open("w", newline="", encoding="utf-8")
    close_target = target is not sys.stdout
    writer = csv.writer(target)
    writer.writerow(["test", "status", "cycles", "notes"])
    for test, status, cycles, notes in rows:
        note_field = "; ".join(notes)
        writer.writerow([test, status, cycles or "", note_field])
    if close_target:
        target.close()

def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "results_dir",
        type=Path,
        nargs="?",
        default=Path("results"),
        help="directory containing *-result.txt files (default: results)",
    )
    parser.add_argument(
        "--csv",
        dest="csv_path",
        type=Path,
        help="optional CSV output path; omit to print Markdown",
    )
    args = parser.parse_args()

    rows = list(iter_results(args.results_dir))
    if args.csv_path:
        emit_csv(rows, args.csv_path)
    else:
        emit_markdown(rows)

if __name__ == "__main__":
    main()

