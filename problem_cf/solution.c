#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int print_chain_fraction(long long numerator, long long denominator){
  assert(denominator != 0);
  int counter = 0;
  int fraction = 0;
  do {
    fraction = numerator / denominator;
    printf("%d ", fraction);
    int remainder = numerator % denominator;
    numerator = denominator;
    denominator = remainder;
  } while(denominator != 0);
  return 0;
}

int main(){
  long long numerator = 0, denominator = 0;
  int res;

  res = scanf("%lli %lli", &numerator, &denominator);
  assert(res == 2);
  print_chain_fraction(numerator, denominator);
}