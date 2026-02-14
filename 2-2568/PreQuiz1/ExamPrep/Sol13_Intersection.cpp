// ข้อ 13: จุดตัดของ 2 Arrays (Sort + Binary Search)
// Time: O((N+M) log(max(N,M)))
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

bool binarySearch(int arr[], int n, int target) {
  int lo = 0, hi = n - 1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (arr[mid] == target)
      return true;
    else if (arr[mid] < target)
      lo = mid + 1;
    else
      hi = mid - 1;
  }
  return false;
}

int main() {
  int n, m;
  cin >> n >> m;

  int a[100001], b[100001];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];

  // Sort ทั้ง 2 array
  mergeSort(a, 0, n - 1);
  mergeSort(b, 0, m - 1);

  // ใช้ array ที่สั้นกว่า scan, array ที่ยาวกว่า binary search
  int result[100001];
  int cnt = 0;

  if (n <= m) {
    for (int i = 0; i < n; i++) {
      if (binarySearch(b, m, a[i]))
        result[cnt++] = a[i];
    }
  } else {
    for (int i = 0; i < m; i++) {
      if (binarySearch(a, n, b[i]))
        result[cnt++] = b[i];
    }
  }

  if (cnt == 0) {
    cout << "EMPTY" << endl;
  } else {
    // result จะ sort อยู่แล้ว เพราะ scan จาก sorted array
    for (int i = 0; i < cnt; i++) {
      if (i > 0)
        cout << " ";
      cout << result[i];
    }
    cout << endl;
  }

  return 0;
}
