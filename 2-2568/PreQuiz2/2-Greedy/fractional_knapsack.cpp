#include <iostream>
using namespace std;

int partition(double ratio[], double weight[], double value[], int index[],
              int low, int high) {
  double pivot = ratio[high];
  int i = low;
  for (int j = low; j < high; j++) {
    if (ratio[j] >= pivot) {
      swap(ratio[i], ratio[j]);
      swap(weight[i], weight[j]);
      swap(value[i], value[j]);
      swap(index[i], index[j]);
      i++;
    }
  }
  swap(ratio[i], ratio[high]);
  swap(weight[i], weight[high]);
  swap(value[i], value[high]);
  swap(index[i], index[high]);
  return i;
}

// Quick Sort ตาม ratio จากมากไปน้อย
void quickSort(double ratio[], double weight[], double value[], int index[],
               int low, int high) {

  if (low < high) {
    int pivotIdx = partition(ratio, weight, value, index, low, high);
    quickSort(ratio, weight, value, index, low, pivotIdx - 1);
    quickSort(ratio, weight, value, index, pivotIdx + 1, high);
  }
}

int main() {
  int n;
  double W;
  cin >> n >> W;

  double weight[10], value[10], ratio[10], fraction[10];
  int index[10]; // เก็บ index เดิมไว้

  // รับ input น้ำหนักและมูลค่า
  for (int i = 0; i < n; i++)
    cin >> weight[i];
  for (int i = 0; i < n; i++)
    cin >> value[i];

  // คำนวณ value/weight ratio และเก็บ index เดิม
  for (int i = 0; i < n; i++) {
    ratio[i] = value[i] / weight[i];
    index[i] = i;
    fraction[i] = 0.0; // เริ่มต้น ยังไม่เลือก item ใดเลย
  }

  // Sort ตาม ratio จากมากไปน้อย (Quick Sort)
  quickSort(ratio, weight, value, index, 0, n - 1);

  // Greedy: เลือก item ที่มี ratio สูงสุดก่อน
  double remaining = W;
  double totalValue = 0.0;

  for (int i = 0; i < n; i++) {
    if (remaining <= 0)
      break;

    if (weight[i] <= remaining) {
      // เลือกทั้งชิ้น
      fraction[index[i]] = 1.0;
      totalValue += value[i];
      remaining -= weight[i];
    } else {
      // เลือกบางส่วน
      double frac = remaining / weight[i];
      fraction[index[i]] = frac;
      totalValue += value[i] * frac;
      remaining = 0;
    }
  }

  // แสดงสัดส่วนการเลือก item ตามลำดับเดิม (ทศนิยม 2 ตำแหน่ง)
  cout << fixed;
  cout.precision(2);
  for (int i = 0; i < n; i++) {
    if (i > 0)
      cout << " ";
    cout << fraction[i];
  }
  cout << endl;

  // แสดงมูลค่ารวมสูงสุด
  cout << totalValue << endl;

  return 0;
}
