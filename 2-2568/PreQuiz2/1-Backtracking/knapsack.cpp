#include <iostream>
#include <climits>
using namespace std;

int MaxV = INT_MIN;
int V[100]; // มูลค่าสินค้า
int W[100]; // น้ำหนักสินค้า
int k;      // น้ำหนักสูงสุดที่ถุงรับได้
int n;      // จำนวนสินค้า

void subsetbinary(int idx, int sum_w, int sum_v) {
  if (sum_w > k) {
    return;
  }
  if (idx > n) {
    if (sum_v > MaxV) {
      MaxV = sum_v;
    }
    return;
  }
  subsetbinary(idx + 1, sum_w + W[idx], sum_v + V[idx]);
  subsetbinary(idx + 1, sum_w, sum_v);
}

int main() {
  // k (น้ำหนักสูงสุดของถุง)
  cin >> k;

  // มูลค่าสินค้า 4 ชิ้น
  n = 4;
  for (int i = 1; i <= n; i++) {
    cin >> V[i];
  }

  // น้ำหนักสินค้า 4 ชิ้น
  for (int i = 1; i <= n; i++) {
    cin >> W[i];
  }

  subsetbinary(1, 0, 0);
  cout << MaxV << endl;

  return 0;
}
