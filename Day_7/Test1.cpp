#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    uint8_t value; // Giá trị của phần tử
    struct Node* next; // Con trỏ đến phần tử tiếp theo trong danh sách liên kết đơn
} Node;

// Hàm thêm phần tử mới vào danh sách liên kết đơn
void insertNode(Node** head_ref, uint8_t new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node)); // Cấp phát bộ nhớ cho phần tử mới
    new_node->value = new_data; // Gán giá trị mới cho phần tử mới
    new_node->next = NULL; // Khởi tạo con trỏ next của phần tử mới là NULL

    Node* current = *head_ref; // Khởi tạo con trỏ current trỏ đến đầu danh sách liên kết

    // Nếu danh sách liên kết đang rỗng hoặc giá trị của phần tử đầu tiên lớn hơn giá trị mới
    if (*head_ref == NULL || (*head_ref)->value >= new_data) {
        // Chèn phần tử mới vào đầu danh sách
        new_node->next = *head_ref;
        *head_ref = new_node;
    } else {
        // Nếu không, điều hướng con trỏ current đến phần tử cuối cùng có giá trị nhỏ hơn giá trị mới
        while (current->next != NULL && current->next->value < new_data) {
            current = current->next;
        }
        // Chèn phần tử mới vào giữa danh sách
        new_node->next = current->next;
        current->next = new_node;
    }
}

// Hàm in các giá trị của mảng khi chưa sắp xếp từ thấp đến cao
void printUnsortedArray(uint8_t assignment3[], int size) {
    printf("Cac gia tri cua mang khi chua sap xep: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", assignment3[i]);
    }
    printf("\n");
}

// Hàm in các giá trị của mảng được sắp xếp
void printSortedArray(Node* head) {
    printf("Cac gia tri cua mang sau khi sap xep: \n");
    Node* current = head; // Khởi tạo con trỏ current trỏ đến đầu danh sách liên kết

    // Duyệt qua từng phần tử trong danh sách liên kết và in giá trị của nó
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

// Hàm xóa phần tử trong danh sách liên kết đơn
void deleteNode(Node** head_ref, uint8_t key) {
    Node* temp = *head_ref; // Con trỏ tạm thời trỏ đến đầu danh sách liên kết
    Node* prev = NULL; // Con trỏ trỏ đến phần tử trước phần tử cần xóa

    // Nếu phần tử cần xóa là phần tử đầu tiên của danh sách liên kết
    if (temp != NULL && temp->value == key) {
        *head_ref = temp->next; // Cập nhật đầu danh sách liên kết
        free(temp); // Giải phóng bộ nhớ của phần tử bị xóa
        return;
    }

    // Duyệt qua danh sách liên kết để tìm phần tử cần xóa
    while (temp != NULL && temp->value != key) {
        prev = temp;
        temp = temp->next;
    }

    // Nếu không tìm thấy phần tử cần xóa
    if (temp == NULL) return;

    // Cập nhật liên kết giữa các phần tử xung quanh phần tử cần xóa
    prev->next = temp->next;
    free(temp); // Giải phóng bộ nhớ của phần tử bị xóa
}

// Kiểm tra xem giá trị có tồn tại trong mảng không
bool isValueExists(uint8_t assignment3[], int size, uint8_t value) {
    for (int i = 0; i < size; i++) {
        if (assignment3[i] == value) {
            return true;
        }
    }
    return false;
}

// Kiểm tra xem vị trí có hợp lệ không
bool isPositionValid(int position) {
    return (position >= 0 && position < 20);
}

// Kiểm tra xem giá trị có hợp lệ không
bool isValueValid(uint8_t value) {
    return (value >= 0 && value <= 100);
}

int main() {
    uint8_t assignment3[20] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                               0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

    Node* head = NULL; // Khởi tạo danh sách liên kết đơn

    int choice;
    uint8_t value, index;

    do {
        printf("\nMenu:\n");
        printf("1. Them gia tri vao phan tu chi dinh cua mang.\n");
        printf("2. Xoa gia tri trong mang.\n");
        printf("3. In gia tri cac phan tu da nhap vao mang.\n");
        printf("4. Ket thuc chuong trinh.\n");
        printf("Chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap vi tri muon them (tu 0 den 19): ");
                scanf("%hhu", &index);
                if (!isPositionValid(index)) {
                    printf("Vi tri khong hop le.\n");
                    break;
                }
                if (assignment3[index] != 0xFF) {
                    printf("Phan tu tai vi tri nay da duoc nhap.\n");
                    break;
                }
                
                printf("Nhap gia tri muon them vao mang: ");
                scanf("%hhu", &value);
                if (!isValueValid(value)) {
                    printf("Gia tri khong hop le.\n");
                    break;
                }
                if (isValueExists(assignment3, 20, value)) {
                    printf("Gia tri da ton tai trong mang.\n");
                    break;
                }
                
                assignment3[index] = value;
                insertNode(&head, value);
                break;
                
            case 2:
                printf("Nhap gia tri muon xoa khoi mang: ");
                scanf("%hhu", &value);
                if (!isValueValid(value)) {
                    printf("Gia tri khong hop le.\n");
                    break;
                }
                if (!isValueExists(assignment3, 20, value)) {
                    printf("Gia tri khong ton tai trong mang.\n");
                    break;
                }
                deleteNode(&head, value);
                for (int i = 0; i < 20; i++) {
                    if (assignment3[i] == value) {
                        assignment3[i] = 0xFF;
                        break;
                    }
                }
                break;
                
            case 3:
                printf("Chon cach in:\n");
                printf("1. In cac gia tri cua mang khi chua sap xep tu thap den cao.\n");
                printf("2. In cac gia tri cua mang da sap xep.\n");
                printf("Chon: ");
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        printUnsortedArray(assignment3, 20);
                        break;
                    case 2:
                        printSortedArray(head);
                        break;
                    default:
                        printf("Lua chon khong hop le.\n");
                }
                break;
                
            case 4:
                printf("Chuong trinh ket thuc.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 4);

    return 0;
}

