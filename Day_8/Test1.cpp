#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Hàm tính checksum
unsigned char calculateChecksum(const char *data, int count) {
    unsigned int sum = 0;
    for (int i = 0; i < count; i += 2) {
        char hex[3];
        strncpy(hex, &data[i], 2);
        hex[2] = '\0';
        sum += (unsigned char)strtol(hex, NULL, 16);
    }
    return ~(unsigned char)(sum & 0xFF) + 1;
}

// Hàm kiểm tra checksum của một dòng SREC
int checkSRECLine(const char *line) {
    int count = strlen(line) - 4; // Bỏ qua Sx và byte count
    char checksumValue[3];
    strncpy(checksumValue, line + count, 2);
    checksumValue[2] = '\0';
    unsigned char checksum = (unsigned char)strtol(checksumValue, NULL, 16);

    // Tính toán checksum
    unsigned char calculatedChecksum = calculateChecksum(line + 2, count - 2);
    return checksum != calculatedChecksum;
}

int main() {
    FILE *inputFile = fopen("input.srec", "r");
    FILE *outputFile = NULL;
    char line[1024];
    int lineNumber = 0;

    if (inputFile == NULL) {
        printf("Khong the mo file input.srec\n");
        return 1;
    }

    while (fgets(line, sizeof(line), inputFile)) {
        lineNumber++;
        // Loại bỏ ký tự xuống dòng
        line[strcspn(line, "\n")] = 0;

        if (checkSRECLine(line)) {
            printf("Loi checksum o dong %d: %s\n", lineNumber, line);
            fclose(inputFile);
            return 1;
        } else {
            if (outputFile == NULL) {
                outputFile = fopen("Output.txt", "w");
                if (outputFile == NULL) {
                    printf("Khong the tao file Output.txt\n");
                    fclose(inputFile);
                    return 1;
                }
            }
            // Parse address và data từ dòng SREC
            char address[5];
            char data[33];
            int dataLength = (line[2] - '0') * 16 + (line[3] - '0') - 5; // Sx, byte count, address và checksum
            strncpy(address, line + 4, 4);
            address[4] = '\0';
            strncpy(data, line + 8, dataLength * 2);
            data[dataLength * 2] = '\0';

            fprintf(outputFile, "%s %s\n", address, data);
        }
    }

    fclose(inputFile);
    if (outputFile != NULL) {
        fclose(outputFile);
    }

    return 0;
}
