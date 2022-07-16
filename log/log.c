#include<stdio.h>
#include<stdint.h>

int clz(uint32_t);

void LOG(int i) {
    int res = clz(i);
    printf("%d %d\n", i, 31 - res);
}

int clz(uint32_t x) {
    int n = 0;
    if (x <= 0x0000ffff) n += 16, x <<= 16;
    if (x <= 0x00ffffff) n +=  8, x <<= 8;
    if (x <= 0x0fffffff) n +=  4, x <<= 4;
    if (x <= 0x3fffffff) n +=  2, x <<= 2;
    if (x <= 0x7fffffff) n ++;
    return n;
}

int main() {
	for (int i = 0; i < 32; ++i) LOG(i);
}
