#include <stdio.h>

int main() {
  unsigned long long a = 0, b = 1, x;
  unsigned long long i;

  printf("70 so dau tien cua day fibonacci:\n");
  for (i = 0; i < 70; i++) {
  	if (i <= 1)
      x = i;
    else {
      x = a + b;
      a = b;
      b = x;
    }
    printf("fibonaci %llu %llu \n", i, x);
  }

  return 0;
}

