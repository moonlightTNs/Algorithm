#include <iostream>
#include <algorithm> // เพิ่ม Library นี้เพื่อใช้ std::sort

using namespace std;

int main() {
  int n;
  cin >> n;

  double length[100];
  for (int i = 0; i < n; i++) {
    cin >> length[i];
  }

  // Greedy: ใช้ฟังก์ชัน sort จาก library (เรียงความยาวไฟล์จากน้อยไปมาก)
  sort(length, length + n);

  // คำนวณ Mean Retrieval Time
  // เวลาเข้าถึงไฟล์ที่ k = length[0] + length[1] + ... + length[k]
  // MRT = ผลรวมเวลาเข้าถึงทุกไฟล์ / n
  double totalTime = 0.0;
  double cumulative = 0.0;

  cout << "Optimal order: ";
  for (int i = 0; i < n; i++) {
    if (i > 0)
      cout << " ";
    cout << length[i];
    cumulative += length[i];
    totalTime += cumulative;
  }
  cout << endl;

  double mrt = totalTime / n;

  cout << fixed;
  cout.precision(2);
  cout << "Mean Retrieval Time: " << mrt << endl;

  return 0;
}