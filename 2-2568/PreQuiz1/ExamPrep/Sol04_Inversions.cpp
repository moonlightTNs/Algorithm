// ข้อ 4: Inversions Count (Modified Merge Sort)
// Time: O(n log n)
#include <iostream>
using namespace std;

int temp[100001];

long long mergeCount(int arr[], int l, int mid, int r) {
  long long inv = 0;
  int i = l, j = mid + 1, k = l;

  while (i <= mid && j <= r) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      // arr[i] > arr[j] --> ทุกตัวจาก i ถึง mid เป็น inversion กับ arr[j]
      inv += (mid - i + 1);
      temp[k++] = arr[j++];
    }
  }
  while (i <= mid)
    temp[k++] = arr[i++];
  while (j <= r)
    temp[k++] = arr[j++];

  for (int x = l; x <= r; x++)
    arr[x] = temp[x];

  return inv;
}

long long mergeSortCount(int arr[], int l, int r) {
  if (l >= r)
    return 0;

  int mid = (l + r) / 2;
  long long inv = 0;

  inv += mergeSortCount(arr, l, mid);     // inversions ฝั่งซ้าย
  inv += mergeSortCount(arr, mid + 1, r); // inversions ฝั่งขวา
  inv += mergeCount(arr, l, mid, r);      // inversions ข้ามฝั่ง

  return inv;
}

int main() {
  int n;
  cin >> n;

  int arr[100001];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << mergeSortCount(arr, 0, n - 1) << endl;

  return 0;
}
