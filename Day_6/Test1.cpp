#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Định nghĩa thông tin nhân viên
struct Employee {
    char name[50];
    int employeeID;
    float salary;
    struct Employee* next;
};

// Khai báo con trỏ đến đầu danh sách liên kết
struct Employee* head = NULL;

// Chức năng thêm nhân viên mới vào danh sách
void addEmployee() {
    struct Employee* newEmployee = (struct Employee*)malloc(sizeof(struct Employee));
    if (newEmployee == NULL) {
        printf("Khong du bo nho!\n");
        return;
    }

    printf("Nhap ten nhan vien: ");
    scanf("%s", newEmployee->name);
    printf("Nhap ma so nhan vien: ");
    scanf("%d", &newEmployee->employeeID);
    printf("Nhap luong nhan vien: ");
    scanf("%f", &newEmployee->salary);

    newEmployee->next = head;
    head = newEmployee;
    printf("Da them nhan vien thanh cong!\n");
}

// Chức năng xóa nhân viên dựa trên tên hoặc mã số
void deleteEmployee() {
    if (head == NULL) {
        printf("Danh sach nhan vien rong.\n");
        return;
    }

    char name[50];
    printf("Nhap ma so hoac ten nhan vien can xoa: ");
    scanf("%s", name);

    struct Employee* current = head;
    struct Employee* prev = NULL;
    int found = 0;

    while (current != NULL) {
        if ((strcmp(current->name, name) == 0) || (atoi(name) == current->employeeID)) {
            found = 1;
            printf("Da tim thay nhan vien:\n");
            printf("Ten: %s\n", current->name);
            printf("Ma so: %d\n", current->employeeID);
            printf("Luong: %.2f\n", current->salary);
            printf("Ban co chac chan muon xoa nhan vien nay: (C|K)");
            char confirm;
            scanf(" %c", &confirm);
            if (confirm == 'C' || confirm == 'c') {
                if (prev == NULL) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                free(current);
                printf("Da xoa nhan vien thanh cong.\n");
            } else {
                printf("Da huy xoa.\n");
            }
            break;
        }
        prev = current;
        current = current->next;
    }

    if (!found) {
        printf("Khong tim thay nhan vien.\n");
    }
}

// Chức năng tìm kiếm thông tin nhân viên dựa trên tên hoặc mã số
void searchEmployee() {
    if (head == NULL) {
        printf("Danh sach nhan vien rong.\n");
        return;
    }

    char name[50];
    printf("Nhap ma so hoac ten nhan vien tim kiem: ");
    scanf("%s", name);

    struct Employee* current = head;
    int found = 0;

    while (current != NULL) {
        if ((strcmp(current->name, name) == 0) || (atoi(name) == current->employeeID)) {
            found = 1;
            printf("Da tim thay nhan vien:\n");
            printf("Ten: %s\n", current->name);
            printf("Ma so: %d\n", current->employeeID);
            printf("Luong: %.2f\n", current->salary);
            break;
        }
        current = current->next;
    }

    if (!found) {
        printf("Khong tim thay nhan vien.\n");
    }
}

// Chức năng hiển thị toàn bộ danh sách nhân viên
void displayEmployees() {
    if (head == NULL) {
        printf("Khong co nhan vien nao trong danh sach.\n");
        return;
    }

    printf("Danh sach nhan vien:\n");
    struct Employee* current = head;
    int count = 1;
    while (current != NULL) {
        printf("Nhan vien %d:\n", count);
        printf("Ten: %s\n", current->name);
        printf("Ma so: %d\n", current->employeeID);
        printf("Luong: %.2f\n", current->salary);
        current = current->next;
        count++;
    }
}

// Hàm main
int main() {
    char choice;

    do {
        printf("\n***He thong quan ly nhan vien***\n");
        printf("1. Them nhan vien\n");
        printf("2. Xoa nhan vien\n");
        printf("3. Tim kiem nhan vien\n");
        printf("4. Hien thi toan bo nhan vien\n");
        printf("5. Thoat\n");
        printf("\n");
        printf("Nhap lua chon cua ban: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                addEmployee();
                break;
            case '2':
                deleteEmployee();
                break;
            case '3':
                searchEmployee();
                break;
            case '4':
                displayEmployees();
                break;
            case '5':
                printf("Thoat khoi chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai\n");
        }
    } while (choice != '5');

    // Giải phóng bộ nhớ khi kết thúc chương trình
    struct Employee* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
