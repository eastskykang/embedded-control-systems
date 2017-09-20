unsigned char sumA;
unsigned char sumB; 
unsigned char result;
int i;

sumA = (unsigned char)u0[0]
| (unsigned char)u0[1] << 1
| (unsigned char)u0[2] << 2
| (unsigned char)u0[3] << 3;

sumB = (unsigned char)u0[4]
| (unsigned char)u0[5] << 1
| (unsigned char)u0[6] << 2
| (unsigned char)u0[7] << 3;

result = sumA + sumB;

for (i = 0; i < 5; i++) {
    y0[i] = (result & (1 << i)) ? 1 : 0;
}
