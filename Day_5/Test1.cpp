#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *inputFile, *numberFile, *letterFile, *specialCharFile;
    char ch;
    int numCount = 0, letterCount = 0, specialCount = 0;

    // Mo tep van ban de doc
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Khong the mo tep input.txt.\n");
        return 1;
    }

    // Mo cac tep de ghi so, chu, va ky tu dac biet
    numberFile = fopen("numbers.txt", "w");
    letterFile = fopen("letters.txt", "w");
    specialCharFile = fopen("special_chars.txt", "w");

    // Doc va xu ly tung ky tu trong tep van ban
    while ((ch = fgetc(inputFile)) != EOF) {
        if (isdigit(ch)) {
            fputc(ch, numberFile); // Ghi so vao tep so
            numCount++;
        } else if (isalpha(ch)) {
            fputc(ch, letterFile); // Ghi chu vao tep chu
            letterCount++;
        } else {
            fputc(ch, specialCharFile); // Ghi ky tu dac biet vao ky tu dac biet
            specialCount++;
        }
    }

    // Đóng tất cả các tệp
    fclose(inputFile);
    fclose(numberFile);
    fclose(letterFile);
    fclose(specialCharFile);

    // In so luong cac ky tu vao terminal
    printf("So: %d\n", numCount);
    printf("Chu cai: %d\n", letterCount);
    printf("Ky tu dac biet: %d\n", specialCount);

    return 0;
}
