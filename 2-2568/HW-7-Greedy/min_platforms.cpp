#include <iostream>
#include <algorithm> 

using namespace std;

// ฟังก์ชันสำหรับคำนวณหาจำนวนชานชาลาที่น้อยที่สุด (Greedy)
int findMinPlatforms(double arrival[], double departure[], int n) {
  int platforms = 0, maxPlatforms = 0;
  int i = 0, j = 0;

  while (i < n && j < n) {
    if (arrival[i] < departure[j]) {
      // รถไฟมาถึง → ต้องการ platform เพิ่ม
      platforms++;
      if (platforms > maxPlatforms)
        maxPlatforms = platforms;
      i++;
    } else {
      // รถไฟออก → คืน platform
      platforms--;
      j++;
    }
  }

  return maxPlatforms;
}

int main() {
  int n;
  cin >> n;

  double arrival[500], departure[500];
  for (int i = 0; i < n; i++) {
    cin >> arrival[i] >> departure[i];
  }

  // ใช้ฟังก์ชัน sort จาก library อัตโนมัติ (เรียงจากน้อยไปมาก)
  sort(arrival, arrival + n);
  sort(departure, departure + n);

  // เรียกใช้ฟังก์ชันหาจำนวนชานชาลา และเก็บค่าไว้ในตัวแปร result
  int result = findMinPlatforms(arrival, departure, n);

  cout << result << endl;

  return 0;
}