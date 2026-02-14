// ข้อ 6: Median of Two Sorted Arrays (Binary Search / D&C)
// Time: O(log(min(n,m)))
#include <iostream>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  int a[500001], b[500001];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];

  // ให้ a เป็น array ที่สั้นกว่าเสมอ
  // ถ้า n > m ให้สลับ
  if (n > m) {
    // สลับ array
    int tempArr[500001];
    for (int i = 0; i < n; i++)
      tempArr[i] = a[i];
    for (int i = 0; i < m; i++)
      a[i] = b[i];
    for (int i = 0; i < n; i++)
      b[i] = tempArr[i];
    int t = n;
    n = m;
    m = t;
  }

  int total = n + m;
  int half = total / 2;

  int lo = 0, hi = n;

  while (lo <= hi) {
    int i = (lo + hi) / 2; // partition ใน a: เอา i ตัวจาก a
    int j = half - i;      // partition ใน b: เอา j ตัวจาก b

    // ค่าที่ขอบ partition
    int aLeft = (i > 0) ? a[i - 1] : -2000000000;
    int aRight = (i < n) ? a[i] : 2000000000;
    int bLeft = (j > 0) ? b[j - 1] : -2000000000;
    int bRight = (j < m) ? b[j] : 2000000000;

    if (aLeft <= bRight && bLeft <= aRight) {
      // เจอ partition ที่ถูกต้อง
      if (total % 2 == 1) {
        // จำนวนคี่ → median คือ min ของฝั่งขวา
        int minRight = (aRight < bRight) ? aRight : bRight;
        cout << minRight << endl;
      } else {
        // จำนวนคู่ → median คือ (maxLeft + minRight) / 2 ปัดลง
        int maxLeft = (aLeft > bLeft) ? aLeft : bLeft;
        int minRight = (aRight < bRight) ? aRight : bRight;
        cout << (maxLeft + minRight) / 2 << endl;
      }
      break;
    } else if (aLeft > bRight) {
      hi = i - 1;
    } else {
      lo = i + 1;
    }
  }

  return 0;
}
