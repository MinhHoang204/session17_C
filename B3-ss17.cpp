#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void nhapChuoi(char **str);
void inDaoNguoc(char *str);
void demSoLuongTu(char *str);
void soSanhChuoi(char *str);
void inHoaChuCai(char *str);
void themChuoi(char **str);

int main() {
    char *str = NULL; 
    int choice;       

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. Nhap vao chuoi khac, so sanh chuoi do voi chuoi ban dau\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Nhap vao chuoi khac va them chuoi do vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                nhapChuoi(&str);
                break;
            case 2:
                inDaoNguoc(str);
                break;
            case 3:
                demSoLuongTu(str);
                break;
            case 4:
                soSanhChuoi(str);
                break;
            case 5:
                inHoaChuCai(str);
                break;
            case 6:
                themChuoi(&str);
                break;
            case 7:
                printf("\nThoat chuong trinh!\n");
                break;
            default:
                printf("\nLua chon khong hop le, vui long nhap lai!\n");
        }
    } while (choice != 7);

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

void inDaoNguoc(char *str) {
    if (str == NULL) {
        printf("\nChua nhap chuoi.\n");
        return;
    }
    printf("\nChuoi dao nguoc: ");
    for (int i = strlen(str) - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

void demSoLuongTu(char *str) {
    if (str == NULL) {
        printf("\nChua nhap chuoi.\n");
        return;
    }
    int count = 0;
    char *token = strtok(str, " ");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    printf("\nSo luong tu trong chuoi: %d\n", count);
}

void soSanhChuoi(char *str) {
    if (str == NULL) {
        printf("\nChua nhap chuoi.\n");
        return;
    }
    char temp[1000];
    printf("\nNhap chuoi khac: ");
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp, "\n")] = '\0';

    if (strlen(temp) > strlen(str)) {
        printf("\nChuoi nhap vao dai hon chuoi ban dau.\n");
    } else if (strlen(temp) < strlen(str)) {
        printf("\nChuoi nhap vao ngan hon chuoi ban dau.\n");
    } else {
        printf("\nHai chuoi co do dai bang nhau.\n");
    }
}

void inHoaChuCai(char *str) {
    if (str == NULL) {
        printf("\nChuoi nhap chuoi.\n");
        return;
    }
    printf("\nChuoi sau khi in hoa: ");
    for (int i = 0; str[i] != '\0'; i++) {
        printf("%c", toupper(str[i]));
    }
    printf("\n");
}

void themChuoi(char **str) {
    if (*str == NULL) {
        printf("\nChuoi nhap chuoi ban dau.\n");
        return;
    }
    char temp[1000];
    printf("\nNhap chuoi khac: ");
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp, "\n")] = '\0';

    *str = (char *)realloc(*str, (strlen(*str) + strlen(temp) + 1) * sizeof(char));
    if (*str == NULL) {
        printf("Khong the cap phat bo nho.\n");
        exit(1);
    }
    strcat(*str, temp);
    printf("\nChuoi sau khi them: %s\n", *str);
}

