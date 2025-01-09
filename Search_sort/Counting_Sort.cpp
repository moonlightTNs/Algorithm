#include <iostream>
using namespace std;


void countingSort(int A[], int n) {

    int maxVal = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > maxVal) {
            maxVal = A[i];
        }
    }

    
    int count[maxVal + 1] = {0};

    
    for (int i = 0; i < n; i++) {
        count[A[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (count[i] > 0) {
            A[index++] = i;
            count[i]--;
        }
    }
}

int main() {
    int arr[] = {8, 4, 2, 2, 8, 3, 3, 1, 5, 5, 9, 2, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    countingSort(arr, n);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
