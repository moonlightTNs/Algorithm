// ข้อ 8: Maximum Subarray Sum (Divide and Conquer) พร้อม index
// Time: O(n log n)
#include <iostream>
using namespace std;

int arr[100001];

// return: {maxSum, startIndex, endIndex}
// ใช้ array 3 ตัวเก็บผลลัพธ์ (ไม่ใช้ struct)
void maxSubArrayDC(int l, int r, long long &bestSum, int &bestL, int &bestR) {
  // Base case
  if (l == r) {
    bestSum = arr[l];
    bestL = l;
    bestR = r;
    return;
  }

  int mid = (l + r) / 2;

  // Divide: หา max subarray ฝั่งซ้ายและขวา
  long long leftSum, rightSum;
  int leftL, leftR, rightL, rightR;
  maxSubArrayDC(l, mid, leftSum, leftL, leftR);
  maxSubArrayDC(mid + 1, r, rightSum, rightL, rightR);

  // Cross: หา max subarray ที่ข้ามจุดกลาง
  long long crossLeftSum = -1e18, tempSum = 0;
  int crossL = mid;
  for (int i = mid; i >= l; i--) {
    tempSum += arr[i];
    if (tempSum > crossLeftSum) {
      crossLeftSum = tempSum;
      crossL = i;
    }
  }

  long long crossRightSum = -1e18;
  tempSum = 0;
  int crossR = mid + 1;
  for (int i = mid + 1; i <= r; i++) {
    tempSum += arr[i];
    if (tempSum > crossRightSum) {
      crossRightSum = tempSum;
      crossR = i;
    }
  }

  long long crossSum = crossLeftSum + crossRightSum;

  // เลือกค่ามากที่สุดจาก 3 ตัว
  if (leftSum >= rightSum && leftSum >= crossSum) {
    bestSum = leftSum;
    bestL = leftL;
    bestR = leftR;
  } else if (rightSum >= leftSum && rightSum >= crossSum) {
    bestSum = rightSum;
    bestL = rightL;
    bestR = rightR;
  } else {
    bestSum = crossSum;
    bestL = crossL;
    bestR = crossR;
  }
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  long long bestSum;
  int bestL, bestR;
  maxSubArrayDC(0, n - 1, bestSum, bestL, bestR);

  cout << bestSum << endl;
  cout << bestL + 1 << " " << bestR + 1 << endl; // 1-indexed

  return 0;
}
