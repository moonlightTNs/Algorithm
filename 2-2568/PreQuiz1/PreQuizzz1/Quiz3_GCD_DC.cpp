// Quiz 3: GCD หา ห.ร.ม. ของ array ด้วย Divide and Conquer
// ใช้ Euclidean Algorithm + D&C แบ่งครึ่ง array
#include <iostream>
using namespace std;

int arr[100001];
int totalCalls = 0; // นับจำนวนรอบ recursive

// Euclidean GCD (Recursive)
int gcd(int a, int b) {
  totalCalls++;
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

// Divide and Conquer: หา GCD ของ arr[l..r]
int gcdDC(int l, int r) {
  totalCalls++;

  // Base case: สมาชิกตัวเดียว
  if (l == r)
    return arr[l];

  // Base case: สมาชิก 2 ตัว
  if (l + 1 == r)
    return gcd(arr[l], arr[r]);

  // Divide
  int mid = (l + r) / 2;

  // Conquer
  int leftGCD = gcdDC(l, mid);
  int rightGCD = gcdDC(mid + 1, r);

  // Combine
  return gcd(leftGCD, rightGCD);
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  totalCalls = 0;
  int result = gcdDC(0, n - 1);

  cout << result << " " << totalCalls << endl;

  return 0;
}
