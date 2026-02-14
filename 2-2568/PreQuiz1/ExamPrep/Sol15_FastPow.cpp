// ข้อ 15: Power Function (Fast Exponentiation / Divide and Conquer)
// Time: O(log b) per query
#include <iostream>
using namespace std;

long long power(long long a, long long b, long long m) {
  // Base case
  if (b == 0)
    return 1 % m;

  // Divide: คำนวณครึ่งหนึ่ง
  long long half = power(a, b / 2, m);

  // Combine
  long long result = (half * half) % m;

  // ถ้า b เป็นเลขคี่ คูณ a อีกที
  if (b % 2 == 1) {
    result = (result * (a % m)) % m;
  }

  return result;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    long long a, b, m;
    cin >> a >> b >> m;
    cout << power(a, b, m) << endl;
  }

  return 0;
}
