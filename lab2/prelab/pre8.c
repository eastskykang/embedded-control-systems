#include <stdio.h>
int main() {

    int32_t TOTAL = 0x00000000;
    uint16_t CURR_FQDPC = 0xFFFF;
    uint16_t PREV_FQDPC = 0x0000;

    TOTAL = TOTAL + (CURR_FQDPC - PREV_FQDPC);

    printf("%x", TOTAL);


    return 0;
}
