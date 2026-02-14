// ข้อ 10: K-th Smallest in Sorted Matrix (Binary Search + Count)
// Time: O(N * log(max - min))
#include <iostream>
using namespace std;

int matrix[501][501];
int N;

// นับจำนวนสมาชิกที่ <= mid
int countLessEqual(int mid) {
  int count = 0;
  int r = N - 1, c = 0; // เริ่มจากมุมล่างซ้าย

  while (r >= 0 && c < N) {
    if (matrix[r][c] <= mid) {
      count += (r + 1); // ทั้งคอลัมน์ c ตั้งแต่แถว 0 ถึง r
      c++;
    } else {
      r--;
    }
  }
  return count;
}

int main() {
  int k;
  cin >> N >> k;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> matrix[i][j];

  // Binary Search บนค่า
  int lo = matrix[0][0];
  int hi = matrix[N - 1][N - 1];

  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    int cnt = countLessEqual(mid);

    if (cnt < k) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }

  cout << lo << endl;

  return 0;
}
