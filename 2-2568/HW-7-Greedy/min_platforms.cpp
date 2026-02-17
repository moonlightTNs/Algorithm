#include <iostream>
using namespace std;

int partition(double arr[], int low, int high) {
  double pivot = arr[high];
  int i = low;
  for (int j = low; j < high; j++) {
    if (arr[j] <= pivot) {
      swap(arr[i], arr[j]);
      i++;
    }
  }
  swap(arr[i], arr[high]);
  return i;
}

void quickSort(double arr[], int low, int high) {
  if (low < high) {
    int pivotIdx = partition(arr, low, high);
    quickSort(arr, low, pivotIdx - 1);
    quickSort(arr, pivotIdx + 1, high);
  }
}

int main() {
  int n;
  cin >> n;

  double arrival[500], departure[500];
  for (int i = 0; i < n; i++) {
    cin >> arrival[i] >> departure[i];
  }

  // Sort เวลามาถึงและเวลาออกแยกกัน (น้อยไปมาก)
  quickSort(arrival, 0, n - 1);
  quickSort(departure, 0, n - 1);

  // Greedy: ใช้ 2 pointer นับจำนวน platform ที่ต้องใช้
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

  cout << maxPlatforms << endl;

  return 0;
}
