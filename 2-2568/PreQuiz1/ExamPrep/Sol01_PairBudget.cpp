// ข้อ 1: จับคู่สินค้าพอดีงบ (Sort + Two Pointer)
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

int main() {
  int n;
  long long k;
  cin >> n >> k;

  int arr[100001];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  // Sort ด้วย Merge Sort
  mergeSort(arr, 0, n - 1);

  // Two Pointer
  int left = 0, right = n - 1;
  bool found = false;

  while (left < right) {
    long long sum = (long long)arr[left] + arr[right];
    if (sum == k) {
      cout << arr[left] << " " << arr[right] << endl;
      found = true;
      break;
    } else if (sum < k) {
      left++;
    } else {
      right--;
    }
  }

  if (!found)
    cout << "NO" << endl;

  return 0;
}
