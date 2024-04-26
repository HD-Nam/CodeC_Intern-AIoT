//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//// Hàm để phân tích tệp SREC đầu vào
//int parse_srec_file(const char *input_file, const char *output_file) {
//    FILE *input_fp = fopen(input_file, "r");
//    FILE *output_fp = fopen(output_file, "w");
//
//    if (input_fp == NULL || output_fp == NULL) {
//        printf("Loi mo tep.\n");
//        return -1;
//    }
//
//    char line[80]; // Giả định độ dài dòng tối đa là 80 ký tự
//    int error_flag = 0;
//
//    while (fgets(line, sizeof(line), input_fp) != NULL) {
//        line[strcspn(line, "\r\n")] = 0; // Loại bỏ ký tự xuống dòng
//        if (line[0] == 'S' && line[1] == '1') {
//            // Phân tích dòng ghi S1
//            char byte_count_str[3], address_str[5], data[64], checksum_str[3];
//            strncpy(byte_count_str, line + 2, 2);
//            byte_count_str[2] = '\0';
//            int byte_count = strtol(byte_count_str, NULL, 16);
//
//            strncpy(address_str, line + 4, 4);
//            address_str[4] = '\0';
//            int address = strtol(address_str, NULL, 16);
//
//            int data_length = byte_count * 2;
//            strncpy(data, line + 8, data_length);
//            data[data_length] = '\0';
//
//            strncpy(checksum_str, line + 8 + data_length, 2);
//            checksum_str[2] = '\0';
//            int checksum = strtol(checksum_str, NULL, 16);
//
//            // Thực hiện tính toán checksum
//            int calculated_checksum = byte_count + (address >> 8) + (address & 0xFF);
//            for (int i = 0; i < data_length; i += 2) {
//                char byte_str[3];
//                strncpy(byte_str, data + i, 2);
//                byte_str[2] = '\0';
//                calculated_checksum += strtol(byte_str, NULL, 16);
//            }
//            calculated_checksum &= 0xFF;
//            calculated_checksum = (~calculated_checksum) & 0xFF;
//
//            if (checksum != calculated_checksum) {
//                printf("Loi checksum trong dong: %s\n", line);
//                error_flag = 1;
//            } else {
//                fprintf(output_fp, "%04X %s\n", address, data);
//            }
//        }
//    }
//
//    fclose(input_fp);
//    fclose(output_fp);
//
//    return error_flag;
//}
//
//int main() {
//    const char *input_file = "input.srec";
//    const char *output_file = "Output.txt";
//
//    int error_flag = parse_srec_file(input_file, output_file);
//
//    if (error_flag) {
//        printf("Co loi xay ra, vui long kiem tra tep Output.\n");
//    } else {
//        printf("Phan tich hoan tat thanh cong. Tep Output: %s\n", output_file);
//    }
//
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

// Struct to hold parsed data
typedef struct {
    int address;
    int length;
    unsigned char *data;
    int checksum;
} SRecord;

// Function to parse SRecord lines
int parseSRecordLine(char *line, SRecord *record) {
    int i;
    int sum = 0;

    // Check if line starts with 'S' character
    if (line[0] != 'S')
        return -1;

    // Parse record type
    sscanf(line, "S%d", &record->length);

    // Parse address
    sscanf(line + 2, "%2x", &record->address);

    // Parse data
    record->data = (unsigned char *)malloc(sizeof(unsigned char) * record->length);
    for (i = 0; i < record->length - 1; i++) {
        sscanf(line + 4 + i * 2, "%2x", &record->data[i]);
        sum += record->data[i];
    }

    // Parse checksum
    sscanf(line + 4 + i * 2, "%2x", &record->checksum);

    // Verify checksum
    sum = (~sum) & 0xFF;
    if (sum != record->checksum)
        return -2;

    return 0;
}

int main() {
    FILE *inputFile, *outputFile;
    char line[MAX_LINE_LENGTH];
    SRecord record;
    int lineNumber = 0;
    int error = 0;

    // Open input file
    inputFile = fopen("input.srec", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Open output file
    outputFile = fopen("Output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        fclose(inputFile);
        return 1;
    }

    // Parse input file
    while (fgets(line, sizeof(line), inputFile)) {
        lineNumber++;
        error = parseSRecordLine(line, &record);
        if (error == -1) {
            printf("Error parsing line %d: Invalid SRecord format\n", lineNumber);
            continue;
        } else if (error == -2) {
            printf("Error parsing line %d: Checksum mismatch\n", lineNumber);
            continue;
        } else {
            // Write to output file
            fprintf(outputFile, "%X ", record.address);
            for (int i = 0; i < record.length - 1; i++) {
                fprintf(outputFile, "%02X", record.data[i]);
            }
            fprintf(outputFile, "\n");
        }
    }

    // Close files
    fclose(inputFile);
    fclose(outputFile);

    printf("Parsing completed.\n");

    return 0;
}

