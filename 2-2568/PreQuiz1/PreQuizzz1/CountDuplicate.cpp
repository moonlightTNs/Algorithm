#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 100005;
// Binary search หาตำแหน่งแรกของ target
int findFirst(int arr[], int n, int target) {
    int low = 0, high = n - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            result = mid;
            high = mid - 1;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

// Binary search หาตำแหน่งสุดท้ายของ target
int findLast(int arr[], int n, int target) {
    int low = 0, high = n - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            result = mid;
            low = mid + 1;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

// นับจำนวน target ใน sorted array
int countOccurrences(int arr[], int n, int target) {
    int first = findFirst(arr, n, target);
    if (first == -1) return 0;
    int last = findLast(arr, n, target);
    return last - first + 1;
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    
    int arr[MAX_SIZE];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int target;
    cout << "Enter target to count: ";
    cin >> target;
    
    // Sort array ก่อนใช้ binary search
    sort(arr, arr + n);
    
    int count = countOccurrences(arr, n, target);
    cout << "Count of " << target << ": " << count << endl;
    
    return 0;
}
