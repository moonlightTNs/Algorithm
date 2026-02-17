#include <iostream>
using namespace std;

int partition(double length[], int low, int high) {
  double pivot = length[high];
  int i = low;
  for (int j = low; j < high; j++) {
    if (length[j] <= pivot) { // น้อยไปมาก
      swap(length[i], length[j]);
      i++;
    }
  }
  swap(length[i], length[high]);
  return i;
}

void quickSort(double length[], int low, int high) {
  if (low < high) {
    int pivotIdx = partition(length, low, high);
    quickSort(length, low, pivotIdx - 1);
    quickSort(length, pivotIdx + 1, high);
  }
}

int main() {
  int n;
  cin >> n;

  double length[100];
  for (int i = 0; i < n; i++) {
    cin >> length[i];
  }

  // Greedy: Sort ความยาวไฟล์จากน้อยไปมาก (Quick Sort)
  quickSort(length, 0, n - 1);

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
