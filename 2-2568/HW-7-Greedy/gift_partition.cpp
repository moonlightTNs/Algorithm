#include <cmath>  
#include <iostream>

using namespace std;

// Partition สำหรับ Quick Sort (เรียงจากมากไปน้อย)
int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low;
  for (int j = low; j < high; j++) {
    if (arr[j] >= pivot) { // มากไปน้อย
      swap(arr[i], arr[j]);
      i++;
    }
  }
  swap(arr[i], arr[high]);
  return i;
}

// Quick Sort (เรียก partition)
void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pivotIdx = partition(arr, low, high);
    quickSort(arr, low, pivotIdx - 1);
    quickSort(arr, pivotIdx + 1, high);
  }
}

int main() {
  int n;
  cin >> n;

  int diffs[150]; // เก็บผลต่างมูลค่าของขวัญแต่ละคู่
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    diffs[i] = abs(a - b); // ใช้ abs จาก cmath
  }

  // Sort ผลต่างจากมากไปน้อย (Greedy: จัดการคู่ที่ต่างกันมากๆ ก่อน)
  quickSort(diffs, 0, n - 1);

  // Greedy: แบ่งผลต่าง sumA และ sumB ให้เท่ากันที่สุด
  // โดยเอาค่ามากสุดไปใส่ฝั่งที่น้อยกว่าเสมอ
  int balance = 0; // ผลรวม diff (ถ้า + คือ sumA มากกว่า, - คือ sumB มากกว่า)

  for (int i = 0; i < n; i++) {
    // ถ้า balance เป็นบวก (A มากกว่า) ให้เอาค่า current ไปลบ (ใส่ B)
    // ถ้า balance เป็นลบ (B มากกว่า) หรือ 0 ให้เอาค่า current ไปบวก (ใส่ A)
    if (balance > 0) {
      balance -= diffs[i];
    } else {
      balance += diffs[i];
    }
  }

  cout << abs(balance) << endl;

  return 0;
}
