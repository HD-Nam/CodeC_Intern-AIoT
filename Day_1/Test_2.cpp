#include <stdio.h>

int UCLN(int a, int b) {
  while (b != 0) {
    int temp = a % b;
    a = b;
    b = temp;
  }
  return a;
}

int BCNN(int a, int b) {
  return (a * b) / UCLN(a, b);
}

int main() {
  int a, b;
  printf("Nhap a = "); scanf("%d", &a);
  printf("Nhap b = "); scanf("%d", &b);

  printf("Uoc chung lon nhat cua %d va %d la: %d\n", a, b, UCLN(a, b));
  printf("Boi chung nho nhat cua %d va %d la: %d\n", a, b, BCNN(a, b));

  return 0;
}






