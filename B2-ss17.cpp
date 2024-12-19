#include <stdio.h>
#include <string.h>
#include <ctype.h>

void nhapChuoi(char **str);
void inChuoi(char *str);
void demChuCai(char *str);
void demChuSo(char *str);
void demKyTuDacBiet(char *str);

int main() {
    char *str = NULL; 
    int choice;       

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi va in ra\n");
        printf("4. Dem so luong chu so trong chuoi va in ra\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi va in ra\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                nhapChuoi(&str);
                break;
            case 2:
                inChuoi(str);
                break;
            case 3:
                demChuCai(str);
                break;
            case 4:
                demChuSo(str);
                break;
            case 5:
                demKyTuDacBiet(str);
                break;
            case 6:
                printf("\nThoat chuong trinh!\n");
                break;
            default:
                printf("\nLua chon khong hop le, vui long nhap lai!\n");
        }
    } while (choice != 6);

    if (str != NULL) {
        free(str);
    }

    return 0;
}

void nhapChuoi(char **str) {
    char temp[1000];
    printf("\nNhap chuoi: ");
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp, "\n")] = '\0'; 

    *str = (char *)malloc((strlen(temp) + 1) * sizeof(char));
    if (*str == NULL) {
        printf("Khong the cap phat bo nho.\n");
        exit(1);
    }
    strcpy(*str, temp);
}

void inChuoi(char *str) {
    if (str == NULL) {
        printf("\nChua nhap chuoi.\n");
        return;
    }
    printf("\nChuoi vua nhap: %s\n", str);
}

void demChuCai(char *str) {
    if (str == NULL) {
        printf("\nChua nhap chuoi.\n");
        return;
    }
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            count++;
        }
    }
    printf("\nSo luong chu cai: %d\n", count);
}

void demChuSo(char *str) {
    if (str == NULL) {
        printf("\nChua nhap chuoi.\n");
        return;
    }
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            count++;
        }
    }
    printf("\nSo luong chu so: %d\n", count);
}

void demKyTuDacBiet(char *str) {
    if (str == NULL) {
        printf("\nChua nhap chuoi.\n");
        return;
    }
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalpha(str[i]) && !isdigit(str[i]) && !isspace(str[i])) {
            count++;
        }
    }
    printf("\nSo luong ki tu dac biet: %d\n", count);
}

