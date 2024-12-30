#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k; 

    int A[10000]; 
    for (int i = 0; i < n; i++) {
        cin >> A[i]; 
    }

    // Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }

    int left = 0, right = n - 1; 
    int min_diff = 1000000000;         

    while (left < right) {
        int sum = A[left] + A[right]; 

        if (sum == k) {
           
            int diff = A[right] - A[left];
            if (diff < min_diff) {
                min_diff = diff; 
            }
            left++;  
            right--; 
        } else if (sum < k) {
            left++; 
        } else {
            right--; 
        }
    }

    cout << min_diff << endl; 
    return 0;
}
