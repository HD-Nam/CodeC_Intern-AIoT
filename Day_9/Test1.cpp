#include <stdio.h>

// Định nghĩa một mảng unsigned short có 1000 phần tử để lưu trữ các giá trị 12-bit
unsigned short array[1000];

// Macro để đọc một phần tử từ mảng dữ liệu
#define READ_ELEMENT(n) (array[n])

// Macro để ghi một phần tử vào mảng dữ liệu
#define WRITE_ELEMENT(n, value) (array[n] = (value))

int main() {
    // Ghi giá trị 665 vào phần tử thứ 3 của mảng
    WRITE_ELEMENT(2, 1243);

    // In ra giá trị của phần tử thứ 3
    printf("%d\n", READ_ELEMENT(2));

    return 0;
}
