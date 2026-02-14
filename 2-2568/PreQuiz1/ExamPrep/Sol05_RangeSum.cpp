// ข้อ 5: Range Sum Query หลัง Sort (Merge Sort + Prefix Sum)
// Time: O(n log n + Q)
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

int main() {
  int n, q;
  cin >> n >> q;

  int arr[100001];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  // Sort
  mergeSort(arr, 0, n - 1);

  // สร้าง prefix sum (1-indexed)
  long long prefix[100002];
  prefix[0] = 0;
  for (int i = 1; i <= n; i++)
    prefix[i] = prefix[i - 1] + arr[i - 1];

  // ตอบ query
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    cout << prefix[r] - prefix[l - 1] << endl;
  }

  return 0;
}
