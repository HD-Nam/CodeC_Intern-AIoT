#include <stdio.h>
#include <math.h>

int main() {
  int x, i, isPrime;

  // Nhap so nguyên x
  printf("Nhap vao so nguyên x (1 <= x <= 100000): ");
  scanf("%d", &x);

  // Kiem tra so nguyen to
  isPrime = 1;
  for (i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) {
      isPrime = 0;
      break;
    }
  }

  // In ket qua
  if (isPrime == 1) {
    printf("%d la so nguyen to.\n", x);
  } else {
    printf("%d khong phai la so nguyen to.\n", x);
  }

  // In ra các so nguyen to nho hon x
  printf("Cac so nguyen to nho hon %d la: ", x);
  for (i = 2; i < x; ++i) {
    isPrime = 1;
    for (int j = 2; j <= i / 2; ++j) {
      if (i % j == 0) {
        isPrime = 0;
        break;
      }
    }
    if (isPrime) {
      printf("%d ", i);
    }
  }

  return 0;
}

