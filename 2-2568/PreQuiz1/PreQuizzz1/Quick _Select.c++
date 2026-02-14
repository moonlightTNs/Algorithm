#include <iostream>
using namespace std;

int arr[] = {1, 5, 10, 4, 8, 2, 6, 9, 20};
int k = 4;
int n = sizeof(arr) / sizeof(arr[0]);


// partition 
int partition(int arr[], int l, int r) {
    int mid = (l + r) / 2;
    // median of three
    if (arr[l] > arr[mid]) swap(arr[l], arr[mid]);
    if (arr[l] > arr[r])   swap(arr[l], arr[r]);
    if (arr[mid] > arr[r]) swap(arr[mid], arr[r]);
    // ใช้ median เป็น pivot
    swap(arr[mid], arr[r]);
    int pivot = arr[r];

    int i = l;
    for (int j = l; j < r; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;   // ตำแหน่ง pivot
}

int quickSelect(int arr[], int low, int high, int k) {
    if (low == high)
        return arr[low];

    int p = partition(arr, low, high);

    int L = p - low;                  // |L| = จำนวน element ที่น้อยกว่า pivot

    if (k == L + 1)                   // หาก k = |L| + 1 จบการทำงาน
        return arr[p];
    else if (k <= L)                  // หาก k <= |L| ทำ partition ฝั่ง L
        return quickSelect(arr, low, p - 1, k);
    else {                            // หาก k > |L| + 1 
        int k = k - (L + 1);     // k' = k - (|L| + 1) แล้วทำ partition ฝั่ง R
        return quickSelect(arr, p + 1, high, k);
    }
}

int main() {
    cout << quickSelect(arr, 0, n - 1, k);
    return 0;
}
