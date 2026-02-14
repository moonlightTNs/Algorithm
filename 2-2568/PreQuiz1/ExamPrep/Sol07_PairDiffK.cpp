// ข้อ 7: จำนวนคู่ที่ผลต่างเท่ากับ K (Sort + Binary Search)
// Time: O(n log n)
#include <iostream>
using namespace std;

int temp[100001];

void merge(int arr[], int l, int mid, int r) {
  int i = l, j = mid + 1, k = l;
  while (i <= mid && j <= r) {
    if (arr[i] <= arr[j])
      temp[k++] = arr[i++];
    else
      temp[k++] = arr[j++];
  }
  while (i <= mid)
    temp[k++] = arr[i++];
  while (j <= r)
    temp[k++] = arr[j++];
  for (int x = l; x <= r; x++)
    arr[x] = temp[x];
}

void mergeSort(int arr[], int l, int r) {
  if (l >= r)
    return;
  int mid = (l + r) / 2;
  mergeSort(arr, l, mid);
  mergeSort(arr, mid + 1, r);
  merge(arr, l, mid, r);
}

// Binary Search: หาว่ามี target ใน arr[l..r] ไหม
bool binarySearch(int arr[], int l, int r, long long target) {
  while (l <= r) {
    int mid = (l + r) / 2;
    if (arr[mid] == target)
      return true;
    else if (arr[mid] < target)
      l = mid + 1;
    else
      r = mid - 1;
  }
  return false;
}

int main() {
  int n;
  long long k;
  cin >> n >> k;

  int arr[100001];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  // Sort
  mergeSort(arr, 0, n - 1);

  // สำหรับแต่ละตัว binary search หา arr[i] + k
  int count = 0;
  for (int i = 0; i < n; i++) {
    long long target = (long long)arr[i] + k;
    if (binarySearch(arr, i + 1, n - 1, target))
      count++;
  }

  cout << count << endl;

  return 0;
}
