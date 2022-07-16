#include <stdio.h>
#include <stdint.h>
#include "log2.inc"

int main() {
  for (int i = 0; i < 64; i++) {
    uint64_t x = (1ULL << i) + 1;
    printf("%016lx %d\n", x, LOG2(x));
  }
}
