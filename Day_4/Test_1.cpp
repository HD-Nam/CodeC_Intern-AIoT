#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Dinh nghia thong tin nhan vien
struct Employee {
    char name[50];
    int employeeID;
    float salary;
};

// Dinh nghia mang chia danh sach nhan vien
struct Employee employees[100];
int numEmployees = 0;

// Chuc nang them nhan vien moi
void addEmployee() {
    if (numEmployees < 100) {
        printf("Nhap ten nhan vien: ");
        scanf("%s", employees[numEmployees].name);
        printf("Nhap ma so nhan vien: ");
        scanf("%d", &employees[numEmployees].employeeID);
        printf("Nhap luong nhan vien: ");
        scanf("%f", &employees[numEmployees].salary);
        numEmployees++;
        printf("Da them nhan vien thanh cong!\n");
    } else {
        printf("Khong the them nhieu nhan vien. Da dat den gioi han toi da!\n");
    }
}

// Chuc nang xoa nhan vien theo ten va ma so
void deleteEmployee() {
    int id;
    char name[50];
    printf("Nhap ma so hoac ten nhan vien can xoa: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < numEmployees; i++) {
        if ((strcmp(employees[i].name, name) == 0) || (atoi(name) == employees[i].employeeID)) {
            found = 1;
            printf("Da tim thay nhan vien:\n");
            printf("Ten: %s\n", employees[i].name);
            printf("Ma so: %d\n", employees[i].employeeID);
            printf("Luong: %.2f\n", employees[i].salary);
            printf("Ban co chac chan muon xoa nhan vien nay: (C|K)");
            char confirm;
            scanf(" %c", &confirm);
            if (confirm == 'C' || confirm == 'K') {
                for (int j = i; j < numEmployees - 1; j++) {
                    employees[j] = employees[j + 1];
                }
                numEmployees--;
                printf("Da xoa nhan vien thanh cong.\n");
            } else {
                printf("Da huy xoa.\n");
            }
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay nhan vien.\n");
    }
}

// Chuc nang tim kiem thong tin theo ten hoac ma so
void searchEmployee() {
    int id;
    char name[50];
    printf("Nhap ma so hoac ten nhan vien tim kiem: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < numEmployees; i++) {
        if ((strcmp(employees[i].name, name) == 0) || (atoi(name) == employees[i].employeeID)) {
            found = 1;
            printf("Da tim thay nhan vien:\n");
            printf("Ten: %s\n", employees[i].name);
            printf("Ma so: %d\n", employees[i].employeeID);
            printf("Luong: %.2f\n", employees[i].salary);
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay nhan vien.\n");
    }
}

// Chuc nang hien thi toan bo nhan vien
void displayEmployees() {
    if (numEmployees == 0) {
        printf("Khong co nhan vien nao trong danh sach.\n");
    } else {
        printf("Danh sach nhan vien:\n");
        for (int i = 0; i < numEmployees; i++) {
            printf("Nhan vien %d:\n", i + 1);
            printf("Ten: %s\n", employees[i].name);
            printf("Ma so: %d\n", employees[i].employeeID);
            printf("Luong: %.2f\n", employees[i].salary);
        }
    }
}

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

    return 0;
}

