// Quiz 1: หาเลขที่ปรากฏมากที่สุด (Mode) ด้วย Divide and Conquer
// ถ้า frequency เท่ากัน เลือกตัวเลขที่น้อยที่สุด
// นับจำนวนรอบ recursive ทั้งหมด
#include <iostream>
using namespace std;

int arr[200001];
int totalCalls = 0;

// นับจำนวน val ใน arr[l..r]
int countVal(int l, int r, int val) {
  int c = 0;
  for (int i = l; i <= r; i++)
    if (arr[i] == val)
      c++;
  return c;
}

// Divide and Conquer: หา mode ใน arr[l..r]
// คืนค่า mode ใน &mode, ความถี่ใน &freq
void findMode(int l, int r, int &mode, int &freq) {
  totalCalls++; // นับทุกครั้งที่เรียก recursive

  // Base case: สมาชิกตัวเดียว
  if (l == r) {
    mode = arr[l];
    freq = 1;
    return;
  }

  int mid = (l + r) / 2;

  // Divide & Conquer
  int modeL, freqL, modeR, freqR;
  findMode(l, mid, modeL, freqL);
  findMode(mid + 1, r, modeR, freqR);

  // Combine
  if (modeL == modeR) {
    // mode เหมือนกัน → รวม frequency
    mode = modeL;
    freq = freqL + freqR;
  } else {
    // mode ต่างกัน → นับจริงทั้ง 2 ตัวใน range [l, r]
    int countL = countVal(l, r, modeL);
    int countR = countVal(l, r, modeR);

    if (countL > countR) {
      mode = modeL;
      freq = countL;
    } else if (countR > countL) {
      mode = modeR;
      freq = countR;
    } else {
      // frequency เท่ากัน → เลือกตัวน้อยกว่า
      mode = (modeL < modeR) ? modeL : modeR;
      freq = countL;
    }
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int mode, freq;
  totalCalls = 0;
  findMode(0, n - 1, mode, freq);

  cout << mode << " " << freq << " " << totalCalls << endl;

  return 0;
}
