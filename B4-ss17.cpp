#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void inputArray(int **arr, int *size) {
    printf("Nhap so phan tu: ");
    scanf("%d", size);
    *arr = (int *)malloc((*size) * sizeof(int));
    for (int i = 0; i < *size; i++) {
        printf("Phan tu [%d]: ", i);
        scanf("%d", &(*arr)[i]);
    }
}

void printEvenNumbers(int *arr, int size) {
    printf("Cac so chan trong mang: ");
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void printPrimeNumbers(int *arr, int size) {
    printf("Cac so nguyen to trong mang: ");
    for (int i = 0; i < size; i++) {
        if (isPrime(arr[i])) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void reverseArray(int *arr, int size) {
    printf("Mang sau khi dao nguoc: ");
    for (int i = size - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sortArray(int *arr, int size, bool ascending) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if ((ascending && arr[i] > arr[j]) || (!ascending && arr[i] < arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Mang sau khi sap xep: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void searchElement(int *arr, int size) {
    int element;
    printf("Nhap phan tu can tim: ");
    scanf("%d", &element);
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            printf("Phan tu %d duoc tim thay tai vi tri %d.\n", element, i);
            found = true;
            break;
        }
    }
    if (!found) {
        printf("Phan tu %d khong ton tai trong mang.\n", element);
    }
}

int main() {
    int *arr = NULL;
    int size = 0;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. In ra cac phan tu la so chan\n");
        printf("3. In ra cac phan tu la so nguyen to\n");
        printf("4. Dao nguoc mang\n");
        printf("5. Sap xep mang\n");
        printf("   5.1 Tang dan\n");
        printf("   5.2 Giam dan\n");
        printf("6. Nhap vao mot phan tu va tim kiem phan tu trong mang\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputArray(&arr, &size);
                break;
            case 2:
                printEvenNumbers(arr, size);
                break;
            case 3:
                printPrimeNumbers(arr, size);
                break;
            case 4:
                reverseArray(arr, size);
                break;
            case 5: {
                int subChoice;
                printf("1. Tang dan\n2. Giam dan\nLua chon cua ban: ");
                scanf("%d", &subChoice);
                if (subChoice == 1) {
                    sortArray(arr, size, true);
                } else if (subChoice == 2) {
                    sortArray(arr, size, false);
                } else {
                    printf("Lua chon khong hop le.\n");
                }
                break;
            }
            case 6:
                searchElement(arr, size);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 7);

    free(arr);
    return 0;
}
