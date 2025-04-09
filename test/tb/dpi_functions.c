#include <stdio.h>
#include <stdint.h>

// Prevent C++ name mangling and use exact types Verilator
 int check(int8_t a0_r, int8_t mcause) {
 if ( (mcause == 11) || (mcause == 3)){
    if (a0_r == 00000000) {
        printf("PASS\n");
        fflush(stdout);  // Ensure output is visible immediately
    } else if (a0_r == 00000001) {
        printf("FAIL\n");
        fflush(stdout);
    } else {
        printf("UNDEFINED value stored in a0 register\n");
        fflush(stdout);
    }
    }

    return 0;
}
