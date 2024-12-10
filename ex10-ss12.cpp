#include <stdio.h>
int input(int arr[]) {
    int n;
    printf("Nhap so phan tu (toi da 1000): ");
    scanf("%d", &n);
    if (n > 100) {
        printf("So phan tu khong hop le gioi han toi da 100 .\n");
        n = 100;
    }
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    return n;
}


void printf_arr(int n, int arr[]) {
    printf("Gia ti cac phan tu dang dc quan ly:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int them_arr(int n, int arr[]) {
    if (n >= 1000) {
        printf("mang da day , k dc them phan tu nua.\n");
        return n;
    }
    int vitri_them, phantu_them;
    printf("nhap vi tri ma ban muon (0-%d): ", n);
    scanf("%d", &vitri_them);
    if (vitri_them < 0 || vitri_them > n) {
        printf("vi tri k hop le.\n");
        return n;
    }
    printf("nhap phan tu can them: ");
    scanf("%d", &phantu_them);
    for (int i = n; i > vitri_them; i--) {
        arr[i] = arr[i - 1];
    }
    arr[vitri_them] = phantu_them;
    return n + 1;
}


int xoa_arr(int n, int arr[]) {
    int vitri_xoa;
    printf("nhap vi tri bat ki ban muon xoa(0-%d): ", n - 1);
    scanf("%d", &vitri_xoa);
    if (vitri_xoa < 0 || vitri_xoa >= n) {
        printf("vi tri k hop le.\n");
        return n;
    }
    for (int i = vitri_xoa; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return n - 1;
}


void sapxep_arrtanglen(int n, int arr[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


void sapxep_arrgiamxuong(int n, int arr[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


int linearSearch(int n, int arr[], int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}


int binarySearch(int n, int arr[], int value) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == value) {
            return mid;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}


int main() {
    int n = 0;
    int arr[1000];
    int choice;

    do {
        printf("MENU\n");
        printf("1. Nhap mang\n");
        printf("2. In mang\n");
        printf("3. Them phan tu \n");
        printf("4. Xoa phan tu \n");
        printf("5. Sap xep tang dan \n");
        printf("6. sap xep giam dan \n");
        printf("7. Tim kiem tuyen tinh\n");
        printf("8.tim kiem nhi phan\n");
        printf("9. Thoat\n");
        printf("lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                n = input(arr);
                break;
            case 2:
                printf_arr(n, arr);
                break;
            case 3:
                n = them_arr(n, arr);
                break;
            case 4:
                n = xoa_arr(n, arr);
                break;
            case 5:
                sapxep_arrtanglen(n, arr);
                printf("mang sau khi sap xep tang dan:\n");
                printf_arr(n, arr);
                break;
            case 6:
                sapxep_arrgiamxuong(n, arr);
                printf("mang sau khi sap xep giam dan:\n");
                printf_arr(n, arr);
                break;
            case 7: {
                int value;
                printf("ban hay nhap gtri can tim: ");
                scanf("%d", &value);
                int pos = linearSearch(n, arr, value);
                if (pos != -1) {
                    printf("da tim thay tai vi trí: %d\n", pos);
                } else {
                    printf("hien ko tim thay gia tri nay.\n");
                }
                break;
            }
            case 8: {
                int value;
                printf("ban hay nhap gtri can tim: ");
                scanf("%d", &value);
                sapxep_arrtanglen(n, arr); 
                int pos = binarySearch(n, arr, value);
                if (pos != -1) {
                    printf("da tim thay tai vi trí: %d\n", pos);
                } else {
                    printf("hien ko tim thay gia tri nay.\n");
                }
                break;
            }
            case 0:
                printf("Thoat chuong trình.\n");
                break;
            default:
                printf("lua chon ko hop le.\n");
        }
    } while (choice != 0);

    return 0;
}

