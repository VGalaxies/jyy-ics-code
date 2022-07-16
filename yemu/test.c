#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "yemu.h"

u8 R[NREG], M[NMEM], oldR[NREG], oldM[NMEM], *newM = M, *newR = R;

void random_rm() {
  for (int i = 0; i < NREG; i++)
    R[i] = rand() & 0xff;
  for (int i = 0; i < NMEM; i++)
    M[i] = rand() & 0xff;
}

#define ASSERT_EQ(a, b) ((u8)(a) == (u8)(b))

#define TESTCASES(_) \
  _(1, 0b11100111, random_rm, ASSERT_EQ(newR[0], oldM[7]) ) \
  _(2, 0b00000100, random_rm, ASSERT_EQ(newR[1], oldR[0]) ) \
  _(3, 0b11100101, random_rm, ASSERT_EQ(newR[0], oldM[5]) ) \
  _(4, 0b00010001, random_rm, ASSERT_EQ(newR[0], oldR[0] + oldR[1]) ) \
  _(5, 0b11110111, random_rm, ASSERT_EQ(newM[7], oldR[0]) ) 

#define MAKETEST(id, inst, precond, postcond) { \
  precond(); \
  memcpy(oldM, M, NMEM); \
  memcpy(oldR, R, NREG); \
  pc = 0; M[pc] = inst; \
  idex(); \
  printf("Test #%d (%s): %s\n", \
    id, #inst, (postcond) ? "PASS" : "FAIL"); \
}

int main() {
  TESTCASES(MAKETEST)
  return 0;
}
