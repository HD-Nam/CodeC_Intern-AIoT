#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define VALUE_RANGE 101

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

int assignment3[ARRAY_SIZE] = {0xFF}; // Khởi tạo mảng với giá trị 0xFF

// Hàm nguyên mẫu
void insertValue(int value, int position);
void deleteValue(int value);
void printArray();
void printMenu();

int main() {
    int choice, position, value;

    while (1) {
        printMenu();
        printf("Lua chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap vi tri (0 den 19): ");
                scanf("%d", &position);
                if (position < 0 || position >= ARRAY_SIZE) {
                    printf("Vi tri khong hop le.\n");
                    break;
                }
                if (assignment3[position] != 0xFF) {
                    printf("Vi tri da duoc lap day.\n");
                    break;
                }
                printf("Nhap gia tri (0 den 100): ");
                scanf("%d", &value);
                if (value < 0 || value >= VALUE_RANGE) {
                    printf("gia tri khong hop le.\n");
                    break;
                }
                insertValue(value, position);
                break;

            case 2:
                printf("Nhap gia tri can xoa (0 den 100): ");
                scanf("%d", &value);
                if (value < 0 || value >= VALUE_RANGE) {
                    printf("gia tri khong hop le.\n");
                    break;
                }
                deleteValue(value);
                break;

            case 3:
                printArray();
                break;

            case 4:
                printf("thoat chuong trinh.\n");
                exit(0);
                break;

            default:
                printf("Lua chon khong hop le. Vui long nhap lai!\n");
                break;
        }
    }

    return 0;
}

// Chèn giá trị vào vị trí đã chỉ định
void insertValue(int value, int position) {
    assignment3[position] = value;

    // Chèn giá trị vào danh sách liên kết
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL || head->data >= value) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

// Xóa giá trị khỏi mảng và danh sách liên kết
void deleteValue(int value) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (assignment3[i] == value) {
            assignment3[i] = 0xFF; // Đánh dấu là đã xóa trong mảng
            break;
        }
    }

    Node* temp = head;
    Node* prev = NULL;

    if (temp != NULL && temp->data == value) {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Khong tim thay gia tri %d .\n", value);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Print array
void printArray() {
    printf("Gia tri mang: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (assignment3[i] != 0xFF) {
            printf("%d ", assignment3[i]);
        }
    }
    printf("\n");
}

// Print menu options
void printMenu() {
    printf("\nMenu:\n");
    printf("1. Nhap mot gia tri vao mot phan tu duoc chi dinh\n");
    printf("2. Xoa mot gia tri khoi danh sach\n");
    printf("3. In mang\n");
    printf("4. Thoat\n");
}
