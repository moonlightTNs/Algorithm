// ข้อ 3: Top-K นักเรียนคะแนนสูงสุด (Sort Multi-key, Parallel Arrays)
// Time: O(n log n)
#include <iostream>
using namespace std;

int tempId[50001], tempScore[50001];

// Merge Sort แบบ 2 parallel arrays
// เรียง: คะแนนมากไปน้อย, ถ้าเท่ากัน รหัสน้อยไปมาก
void merge(int id[], int score[], int l, int mid, int r) {
  int i = l, j = mid + 1, k = l;
  while (i <= mid && j <= r) {
    // เปรียบเทียบ: score มากกว่ามาก่อน, ถ้าเท่ากัน id น้อยมาก่อน
    if (score[i] > score[j] || (score[i] == score[j] && id[i] < id[j])) {
      tempId[k] = id[i];
      tempScore[k] = score[i];
      k++;
      i++;
    } else {
      tempId[k] = id[j];
      tempScore[k] = score[j];
      k++;
      j++;
    }
  }
  while (i <= mid) {
    tempId[k] = id[i];
    tempScore[k] = score[i];
    k++;
    i++;
  }
  while (j <= r) {
    tempId[k] = id[j];
    tempScore[k] = score[j];
    k++;
    j++;
  }
  for (int x = l; x <= r; x++) {
    id[x] = tempId[x];
    score[x] = tempScore[x];
  }
}

void mergeSort(int id[], int score[], int l, int r) {
  if (l >= r)
    return;
  int mid = (l + r) / 2;
  mergeSort(id, score, l, mid);
  mergeSort(id, score, mid + 1, r);
  merge(id, score, l, mid, r);
}

int main() {
  int n, k;
  cin >> n >> k;

  int id[50001], score[50001];
  for (int i = 0; i < n; i++)
    cin >> id[i] >> score[i];

  mergeSort(id, score, 0, n - 1);

  for (int i = 0; i < k; i++)
    cout << id[i] << " " << score[i] << endl;

  return 0;
}
