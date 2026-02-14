// ข้อ 14: หาช่วงที่มีจำนวนคู่-คี่สมดุล (Transform + Sort)
// Time: O(n log n)
#include <iostream>
using namespace std;

int tempVal[100002], tempIdx[100002];

// Sort parallel arrays (val[], idx[]) ตาม val น้อยไปมาก
// ถ้า val เท่ากัน sort ตาม idx น้อยไปมาก
void merge(int val[], int idx[], int l, int mid, int r) {
  int i = l, j = mid + 1, k = l;
  while (i <= mid && j <= r) {
    if (val[i] < val[j] || (val[i] == val[j] && idx[i] < idx[j])) {
      tempVal[k] = val[i];
      tempIdx[k] = idx[i];
      k++;
      i++;
    } else {
      tempVal[k] = val[j];
      tempIdx[k] = idx[j];
      k++;
      j++;
    }
  }
  while (i <= mid) {
    tempVal[k] = val[i];
    tempIdx[k] = idx[i];
    k++;
    i++;
  }
  while (j <= r) {
    tempVal[k] = val[j];
    tempIdx[k] = idx[j];
    k++;
    j++;
  }
  for (int x = l; x <= r; x++) {
    val[x] = tempVal[x];
    idx[x] = tempIdx[x];
  }
}

void mergeSort(int val[], int idx[], int l, int r) {
  if (l >= r)
    return;
  int mid = (l + r) / 2;
  mergeSort(val, idx, l, mid);
  mergeSort(val, idx, mid + 1, r);
  merge(val, idx, l, mid, r);
}

int main() {
  int n;
  cin >> n;

  int arr[100001];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  // Transform: คี่ → -1, คู่ → +1
  // สร้าง prefix sum (index 0 = 0, index i = sum of first i elements)
  int prefVal[100002]; // prefix sum values
  int prefIdx[100002]; // original indices

  prefVal[0] = 0;
  prefIdx[0] = 0;
  for (int i = 1; i <= n; i++) {
    int contrib = (arr[i - 1] % 2 == 0) ? 1 : -1;
    prefVal[i] = prefVal[i - 1] + contrib;
    prefIdx[i] = i;
  }

  // Sort prefix sum ตามค่า (ถ้าเท่ากัน ตาม index)
  mergeSort(prefVal, prefIdx, 0, n);

  // หา max length: prefix sum ค่าเหมือนกัน → ผลต่าง index ที่ห่างสุด
  int maxLen = 0;
  int i = 0;
  while (i <= n) {
    int j = i;
    // หากลุ่มที่มี prefVal เท่ากัน
    while (j <= n && prefVal[j] == prefVal[i])
      j++;
    // ในกลุ่ม i..j-1: min index = prefIdx[i], max index = prefIdx[j-1]
    // (เพราะ secondary sort ตาม index)
    int len = prefIdx[j - 1] - prefIdx[i];
    if (len > maxLen)
      maxLen = len;
    i = j;
  }

  cout << maxLen << endl;

  return 0;
}
