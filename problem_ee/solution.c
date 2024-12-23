#include <stdio.h>
#include <stdlib.h>

void iterative_extended_gcd(long long x, long long y, long long *a, long long *b, long long *d) {
    long long a0 = 1, b0 = 0;
    long long a1 = 0, b1 = 1;
    long long original_x = x, original_y = y;

    while (y != 0) {
        long long q = x / y;
        long long r = x % y;

        x = y;
        y = r;

        long long temp_a = a1;
        long long temp_b = b1;

        a1 = a0 - q * a1;
        b1 = b0 - q * b1;

        a0 = temp_a;
        b0 = temp_b;
    }
    if (x < 0) {
        a0 = -a0;
        b0 = -b0;
        x = -x;
    }
    *a = a0;
    *b = b0;
    *d = x;
}

int main() {
    long long x, y;

    scanf("%lld %lld", &x, &y);
    long long a, b, d;
    iterative_extended_gcd(x, y, &a, &b, &d);
    printf("%lld %lld %lld\n", a, b, d);
    return 0;
}