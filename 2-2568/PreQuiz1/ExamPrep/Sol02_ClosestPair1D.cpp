// ข้อ 2: Closest Pair Distance 1D (Divide and Conquer + Sort)
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

// Divide and Conquer: หาระยะห่างน้อยสุดใน sorted array
int closestPairDC(int arr[], int l, int r) {
  // Base case
  if (l >= r)
    return 2000000000; // INT_MAX equivalent
  if (r - l == 1)
    return arr[r] - arr[l];

  int mid = (l + r) / 2;

  // Divide: หาค่าน้อยสุดในแต่ละฝั่ง
  int leftMin = closestPairDC(arr, l, mid);
  int rightMin = closestPairDC(arr, mid + 1, r);

  // Combine: เปรียบเทียบกับระยะข้ามฝั่ง
  int crossMin = arr[mid + 1] - arr[mid];

  int result = leftMin;
  if (rightMin < result)
    result = rightMin;
  if (crossMin < result)
    result = crossMin;

  return result;
}

int main() {
  int n;
  cin >> n;

  int arr[100001];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  // Sort ก่อน
  mergeSort(arr, 0, n - 1);

  // Divide and Conquer
  cout << closestPairDC(arr, 0, n - 1) << endl;

  return 0;
}
