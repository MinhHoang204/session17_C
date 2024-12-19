#include <stdio.h>
#include <stdlib.h>

void nhapMang(int **arr, int *n);
void hienThiMang(int *arr, int n);
int tinhDoDaiMang(int *n);
int tinhTong(int *arr, int n);
int phanTuLonNhat(int *arr, int n);

int main() {
    int *arr = NULL; 
    int n = 0;      
    int choice;      

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. Hien thi cac phan tu trong mang\n");
        printf("3. Tinh do dai mang\n");
        printf("4. Tinh tong cac phan tu trong mang\n");
        printf("5. Hien thi phan tu lon nhat\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMang(&arr, &n);
                break;
            case 2:
                hienThiMang(arr, n);
                break;
            case 3:
                printf("\nDo dai cua mang la: %d\n", tinhDoDaiMang(&n));
                break;
            case 4:
                printf("\nTong cac phan tu trong mang la: %d\n", tinhTong(arr, n));
                break;
            case 5:
                printf("\nPhan tu lon nhat la: %d\n", phanTuLonNhat(arr, n));
                break;
            case 6:
                printf("\nThoat chuong trinh!\n");
                break;
            default:
                printf("\nLua chon khong hop le, vui long nhap lai!\n");
        }
    } while (choice != 6);

    if (arr != NULL) {
        free(arr);
    }

    return 0;
}

void nhapMang(int **arr, int *n) {
    printf("\nNhap so phan tu cua mang: ");
    scanf("%d", n);

    *arr = (int *)malloc((*n) * sizeof(int));
    if (*arr == NULL) {
        printf("Khong the cap phat bo nho.\n");
        exit(1);
    }

    printf("Nhap tung phan tu:\n");
    for (int i = 0; i < *n; i++) {
        printf("Phan tu[%d]: ", i);
        scanf("%d", (*arr) + i);
    }
}

void hienThiMang(int *arr, int n) {
    if (arr == NULL || n == 0) {
        printf("\nMang rong.\n");
        return;
    }

    printf("\nCac phan tu trong mang: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int tinhDoDaiMang(int *n) {
    return *n;
}

int tinhTong(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += *(arr + i);
    }
    return sum;
}

int phanTuLonNhat(int *arr, int n) {
    if (arr == NULL || n == 0) {
        printf("\nMang rong, khong co phan tu lon nhat.\n");
        return -1;
    }

    int max = *arr;
    for (int i = 1; i < n; i++) {
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }
    return max;
}

