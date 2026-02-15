#include <iostream>
using namespace std;

// ฟังก์ชันตรวจสอบเลขคี่หรือคู่
// คืนค่า true ถ้าเป็นคู่, false ถ้าเป็นคี่
bool checkOddEven(int num) {
  if (num % 2 == 0) {
    return true;
  } else {
    return false;
  }
}

// ฟังก์ชัน swap สลับค่า
void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

// Partition สำหรับเรียงจากน้อยไปมาก (Ascending)
int partitionAsc(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return i + 1;
}

// Partition สำหรับเรียงจากมากไปน้อย (Descending)
int partitionDesc(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (arr[j] >= pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return i + 1;
}

// Quick Sort เรียงจากน้อยไปมาก (Ascending)
void sortAscending(int arr[], int low, int high) {
  if (low < high) {
    int pi = partitionAsc(arr, low, high);
    sortAscending(arr, low, pi - 1);
    sortAscending(arr, pi + 1, high);
  }
}

// Quick Sort เรียงจากมากไปน้อย (Descending)
void sortDescending(int arr[], int low, int high) {
  if (low < high) {
    int pi = partitionDesc(arr, low, high);
    sortDescending(arr, low, pi - 1);
    sortDescending(arr, pi + 1, high);
  }
}

int main() {
  int n;
  cin >> n;

  int data[100];
  for (int i = 0; i < n; i++) {
    cin >> data[i];
  }

  // Step 1: หาค่าน้อยที่สุด
  int minVal = data[0];
  for (int i = 1; i < n; i++) {
    if (data[i] < minVal) {
      minVal = data[i];
    }
  }

  // Step 2: แยกเลขคี่และเลขคู่
  int odd[100], even[100];
  int oddCount = 0, evenCount = 0;

  for (int i = 0; i < n; i++) {
    if (checkOddEven(data[i])) { // true = คู่
      even[evenCount++] = data[i];
    } else { // false = คี่
      odd[oddCount++] = data[i];
    }
  }

  // Step 3: เรียงลำดับตามเงื่อนไข
  if (checkOddEven(minVal)) { // true = คู่
    // ค่าน้อยสุดเป็นคู่
    sortAscending(even, 0, evenCount - 1); // คู่: น้อย -> มาก
    sortDescending(odd, 0, oddCount - 1);  // คี่: มาก -> น้อย
  } else {
    // ค่าน้อยสุดเป็นคี่
    sortAscending(odd, 0, oddCount - 1);    // คี่: น้อย -> มาก
    sortDescending(even, 0, evenCount - 1); // คู่: มาก -> น้อย
  }

  // Step 4: แสดงผล - กลุ่มที่มีตัวแรกน้อยกว่า แสดงก่อน
  // หาตัวแรกของแต่ละกลุ่ม
  int firstOdd;
  if (oddCount > 0) {
    firstOdd = odd[0];
  } else {
    firstOdd = 999999;
  }

  int firstEven;
  if (evenCount > 0) {
    firstEven = even[0];
  } else {
    firstEven = 999999;
  }

  if (firstOdd <= firstEven) {
    // แสดงคี่ก่อน แล้วตามด้วยคู่ (cout ปกติ)
    for (int i = 0; i < oddCount; i++) {
      cout << odd[i];
      if (i != oddCount - 1 || evenCount > 0) cout << " ";
    }
    for (int i = 0; i < evenCount; i++) {
      cout << even[i];
      if (i != evenCount - 1) cout << " ";
    }
  } else {
    // แสดงคู่ก่อน แล้วตามด้วยคี่ (cout ปกติ)
    for (int i = 0; i < evenCount; i++) {
      cout << even[i];
      if (i != evenCount - 1 || oddCount > 0) cout << " ";
    }
    for (int i = 0; i < oddCount; i++) {
      cout << odd[i];
      if (i != oddCount - 1) cout << " ";
    }
  }
  cout << endl;

  return 0;
}
