#include <iostream>
using namespace std;

// ฟังก์ชันรวม (Merge) สองส่วนย่อยของอาร์เรย์
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // สร้างอาร์เรย์ชั่วคราวสำหรับการรวม
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // รวมข้อมูลกลับเข้าไปในอาร์เรย์หลัก
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // คัดลอกส่วนที่เหลือ
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// ฟังก์ชัน Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);       // จัดเรียงครึ่งซ้าย
        mergeSort(arr, mid + 1, right); // จัดเรียงครึ่งขวา
        merge(arr, left, mid, right);   // รวมสองครึ่ง
    }
}

// ฟังก์ชันค้นหาตำแหน่งเริ่มต้นของ target
int findLowerBound(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid;
    }
    return (arr[low] == target) ? low : -1;
}

// ฟังก์ชันค้นหาตำแหน่งสุดท้ายของ target
int findUpperBound(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low < high) {
        int mid = low + (high - low + 1) / 2;
        if (arr[mid] > target)
            high = mid - 1;
        else
            low = mid;
    }
    return (arr[low] == target) ? low : -1;
}

// ฟังก์ชันหลักในการหาจำนวนสมาชิก
int countOccurrences(int arr[], int n, int target) {
    int lower = findLowerBound(arr, n, target);
    if (lower == -1) return -1; // ไม่มีสมาชิกที่ตรงกับ target

    int upper = findUpperBound(arr, n, target);
    return upper - lower + 1;
}

int main() {
    int n, k;
    cin >> n >> k; // รับค่า n และ k

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // รับสมาชิกของอาร์เรย์
    }

    mergeSort(arr, 0, n - 1); // เรียงลำดับอาร์เรย์ด้วย Merge Sort

    int result = countOccurrences(arr, n, k);
    cout << result << endl;

    return 0;
}
