#include <stdio.h>
#include <stdint.h>

 int check(int8_t a0_r, int8_t mcause) {
 if ( (mcause == 11) || (mcause == 3)){
    if (a0_r == 00000000) {
        printf("PASS\n");
    } else if (a0_r == 00000001) {
        printf("FAIL\n");
    } else {
        printf("UNDEFINED value stored in a0 register\n");
    }
    }

    return 0;
}
