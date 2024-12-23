#include <stdio.h>
#include <stdlib.h>

// Function to calculate GCD using the Euclidean algorithm
unsigned long long gcd(unsigned long long x, unsigned long long y) {
  while (y != 0) {
    unsigned long long temp = x % y;
    x = y;
    y = temp;
  }
  return x;
}

int main() {
  long long x_r = 0, y_r = 0;
  unsigned long long x, y, g;

  if (scanf("%lli %lli", &x_r, &y_r) != 2) {
    return EXIT_FAILURE;
  }

  x = (unsigned long long)labs(x_r);
  y = (unsigned long long)labs(y_r);

  g = gcd(x, y);

  printf("%llu\n", g);

  return EXIT_SUCCESS;
}