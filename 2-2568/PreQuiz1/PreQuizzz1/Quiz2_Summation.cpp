// Quiz 2: Summation - หา n ที่ sum(1..n) = x ด้วย Binary Search (Recursive)
// ถ้าไม่มี n ที่เป็นไปได้ → ตอบ 0
// Time: O(log x)
#include <iostream>
using namespace std;

int totalCalls = 0; // นับจำนวนรอบ recursive

int binarySearch(long long lo, long long hi, long long x) {
  totalCalls++; // นับทุกครั้งที่เรียก recursive
  if (lo > hi)
    return 0; // ไม่เจอ

  long long mid = lo + (hi-lo) / 2;
  long long sum = mid * (mid + 1) / 2;

  if (sum == x)
    return mid; // เจอ!
  else if (sum < x)
    return binarySearch(mid + 1, hi, x); // ไปขวา
  else
    return binarySearch(lo, mid - 1, x); // ไปซ้าย
}

int main() {
  long long x;
  cin >> x;

  totalCalls = 0;
  int result = binarySearch(1, 10000, x);

  cout << result << " " << totalCalls << endl;

  return 0;
}
