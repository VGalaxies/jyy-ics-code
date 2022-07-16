#define SUM(T, st, ed, d) ({ \
  T s = 0; \
  for (int i = st; i != ed + d; i += d) \
    s += (T)1 / i; \
  s; \
})

#include <stdio.h>

#define N 1000000
int main() {
	printf("%.16f\n", SUM(float, 1, N, 1));
	printf("%.16f\n", SUM(float, N, 1, -1));
	printf("%.16lf\n", SUM(double, 1, N, 1));
	printf("%.16lf\n", SUM(double, N, 1, -1));
}

