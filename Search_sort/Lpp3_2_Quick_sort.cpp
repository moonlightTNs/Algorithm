#include <bits/stdc++.h>
using namespace std;

int partition(int a[], int l, int r, int pivots[], int& pivotCount) {
    int mid = (l + r) / 2;
    if (a[l] > a[mid]) swap(a[l], a[mid]);
    if (a[l] > a[r]) swap(a[l], a[r]);
    if (a[mid] > a[r]) swap(a[mid], a[r]);
    swap(a[r], a[mid]); 
    int pivot = a[r];

    int i = l - 1, j = r;
    while (1) {
        do {
            i++;
        } while (a[i] < pivot);

        do {
            j--;
        } while (j > l && a[j] > pivot);

        if (i >= j) break;

        swap(a[i], a[j]);
    }
    swap(a[i], a[r]);
    pivots[pivotCount++] = i + 1; 
    return i;
}

void quick_sort(int a[], int l, int r, int pivots[], int& pivotCount) {
    if (l < r) {
        int p = partition(a, l, r, pivots, pivotCount);
        quick_sort(a, l, p - 1, pivots, pivotCount);
        quick_sort(a, p + 1, r, pivots, pivotCount);
    }
}

int main() {
    int n;
    cin >> n;

    if (n <= 1 || n >= 500) {
        return 0;
    }

    int a[n];
    for (int i = 0; i < n; i++) {
        if (!(cin >> a[i])) {
            return 0;
        }
        if (a[i] < -10000 || a[i] > 10000) {
            return 0;
        }
    }

    if (n == 1) {
        cout << "1" << endl;
        cout << a[0] << endl;
        return 0;
    }

    int pivots[n];
    int pivotCount = 0;

    quick_sort(a, 0, n - 1, pivots, pivotCount);

    bool isSorted = true;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            isSorted = false;
            break;
        }
    }

    if (!isSorted) {
        return 0;
    }

    for (int i = 0; i < pivotCount; i++) {
        cout << pivots[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
