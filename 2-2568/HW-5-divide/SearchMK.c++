#include <iostream>
#include <cmath>
using namespace std;


int partition(int a[], int l, int r) {
    int mid = (l + r) / 2;

    if (a[l] > a[mid]) swap(a[l], a[mid]);
    if (a[l] > a[r]) swap(a[l], a[r]);
    if (a[mid] > a[r]) swap(a[mid], a[r]);

    swap(a[mid], a[r]);

    int pivot = a[r];

    int i = l;
    for (int j = l; j < r; j++) {
        if (a[j] < pivot) {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[r]);
    return i;
}

void quicksort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quicksort(a, low, p - 1);
        quicksort(a, p + 1, high);
    }
}

//หา left index ที่เหมาะสม 
int binarySearchLeft(int A[], int n, int M, int k) {
    int low = 0;
    int high = n - k;
    
    while (low < high) {
        int mid = (low + high) / 2;
        
        if (abs(A[mid] - M) > abs(A[mid + k] - M)) { // เลื่อนขวา
            low = mid + 1;
        } else {
            high = mid;  // เลื่อนซ้าย
        }
    }
    return low;
}

void Search(int A[], int n, int M, int k) {
    quicksort(A, 0, n - 1);

    int left = binarySearchLeft(A, n, M, k);
    int right = left + k - 1;

    cout << "Output: A[" << left << "] ... A[" << right << "]" << endl;
    cout << "Result: ";
    for (int j = left; j <= right; j++) {
        cout << A[j] << " ";
    }
    cout << endl;
}

int main() {
    int A[] = {10, 12, 15, 17, 18, 20, 25};
    int n = sizeof(A) / sizeof(A[0]);
    int M = 8;
    int k = 2;

    Search(A, n, M, k);

    return 0;
}
