#include <stdio.h>
#include <string.h>

// Hàm thay thế ký tự 'e' thành 'ef' trong chuỗi
void replaceChar(char *str, char find) {
    int i, j;
    int len = strlen(str);
    
    // Duyệt qua từng ký tự trong chuỗi
    for (i = 0; i < len; ++i) {
        // Nếu tìm thấy ký tự 'e'
        if (str[i] == find) {
            // Dời tất cả ký tự sang phải để tạo chỗ trống cho 'f'
            for (j = len + 1; j > i + 1; --j) {
                str[j] = str[j - 1];
            }
            // Thay thế 'e' bằng 'e' và 'f'
            str[i] = find;
            str[i + 1] = 'f';
            // Cập nhật độ dài của chuỗi mới
            len++;
            // Dịch i sang phải 1 bước để tránh thực hiện kiểm tra lại các ký tự đã thay thế
            i++;
        }
    }
}

int main() {
    char str[101]; // 100 ký tự +1 ký tự kết thúc chuỗi '\0'
    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);
    
    // Xóa ký tự '\n' ở cuối chuỗi do fgets() tự động thêm vào
    str[strcspn(str, "\n")] = '\0';
    
    // Thực hiện thay thế ký tự 'e' thành 'ef' cạnh nhau
    replaceChar(str, 'e');
    
    // In chuỗi sau khi thay thế
    printf("Chuoi sau khi thay the: %s\n", str);

    return 0;
}

