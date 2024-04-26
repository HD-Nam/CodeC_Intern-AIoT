#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Hàm loại bỏ các ký tự không phải chữ cái và loại bỏ các khoảng trắng dư thừa
void processString(char *str) {
    int i, j;
    int length = strlen(str);
    int isPreviousSpace = 0; // Biến để kiểm tra xem ký tự trước đó có phải là khoảng trắng không

    for (i = 0, j = 0; i < length; i++) {
        if (isalpha(str[i])) { // Nếu là chữ cái
            str[j++] = str[i]; // Giữ nguyên ký tự
            isPreviousSpace = 0; // Đặt lại biến cờ
        } else if (isspace(str[i])) { // Nếu là khoảng trắng
            if (!isPreviousSpace) { // Nếu ký tự trước đó không phải là khoảng trắng
                str[j++] = ' '; // Giữ lại 1 khoảng trắng
                isPreviousSpace = 1; // Đặt biến cờ để xác định đã gặp khoảng trắng
            }
        }
        // Các trường hợp khác, bỏ qua (không làm gì)
    }
    str[j] = '\0'; // Kết thúc chuỗi sau khi xử lý
}

// Hàm in ra chuỗi đã được xử lý
void printProcessedString(char *str) {
    printf("Chuoi sau khi xu ly: %s\n", str);
}

// Hàm in ra chuỗi theo thứ tự đảo ngược
void printReversedString(char *str) {
    int length = strlen(str);
    printf("Chuoi dao nguoc: ");
    for (int i = length - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

// Hàm chuyển các ký tự chữ hoa thành chữ thường và in ra
void printLowercaseString(char *str) {
    int length = strlen(str);
    printf("Chuoi chuyen ve chu thuong: ");
    for (int i = 0; i < length; i++) {
        printf("%c", tolower(str[i]));
    }
    printf("\n");
}

int main() {
    char str[1000];
    
    printf("Nhap vao mot chuoi: ");
    fgets(str, sizeof(str), stdin);

    // Xử lý chuỗi
    processString(str);

    // a. In ra chuỗi sau khi đã xử lí
    printProcessedString(str);

    // b. In ra chuỗi theo thứ tự các ký tự đảo ngược
    printReversedString(str);

    // c. Convert các ký tự chữ hoa thành chữ thường rồi in ra.
    printLowercaseString(str);

    return 0;
}
