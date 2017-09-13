#include <stdio.h>
#include <stdint.h>
int main() {

    int32_t TOTAL = 0x0000FFFF;
    uint16_t CURR_FQDPC = 0x0000;
    uint16_t PREV_FQDPC = 0xFFFF;

    TOTAL = TOTAL + (CURR_FQDPC - PREV_FQDPC);
    printf("%08x", TOTAL);

    return 0;
}
