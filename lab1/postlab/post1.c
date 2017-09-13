union {

    unsigned short R; 

    struct {
        unsigned short a:4;
        unsigned short b:5;
        unsigned short c:7;
    } B;
} input;

int main() {

    short input; // input 

    // a (using union)
    input.B.b = 0b11101;

    // b (using shift and masking)
    short and_mask = 0xF07F; // output 
    short or_mask = 0b11101;
    short output = 0;

    or_mask = or_mask << 7;
    output = input & and_mask | or_mask;

    return 0;
}
