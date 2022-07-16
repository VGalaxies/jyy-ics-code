#include <stdint.h>

typedef uint8_t u8;
#define NMEM 16

enum { RA, R1, R2, R3, PC, NREG };
extern u8 M[NMEM], R[NREG];
#define pc (R[PC])

void idex();
