// ข้อ 11: ทำนายอันดับ (Sort มากไปน้อย + Binary Search)
// Time: O((N + M) log N)
#include <iostream>
using namespace std;

int temp[100001];

// Merge Sort เรียงจากมากไปน้อย
void merge(int arr[], int l, int mid, int r) {
  int i = l, j = mid + 1, k = l;
  while (i <= mid && j <= r) {
    if (arr[i] >= arr[j])
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

// Binary Search: หาจำนวนคนที่คะแนน > target (ใน array sort มากไปน้อย)
// = ตำแหน่งแรกที่ ≤ target
int countGreater(int arr[], int n, int target) {
  int lo = 0, hi = n;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (arr[mid] > target)
      lo = mid + 1;
    else
      hi = mid;
  }
  return lo; // จำนวนคนที่คะแนนมากกว่า target
}

int main() {
  int n, m;
  cin >> n >> m;

  int score[100001];
  for (int i = 0; i < n; i++)
    cin >> score[i];

  int newScore[100001];
  for (int i = 0; i < m; i++)
    cin >> newScore[i];

  // Sort จากมากไปน้อย
  mergeSort(score, 0, n - 1);

  // ทำนายอันดับ
  for (int i = 0; i < m; i++) {
    int rank = countGreater(score, n, newScore[i]) + 1;
    if (i > 0)
      cout << " ";
    cout << rank;
  }
  cout << endl;

  return 0;
}
