#include "a.h"

extern inline void f();

void g() {
	f();
	printf("g()\n");
}
