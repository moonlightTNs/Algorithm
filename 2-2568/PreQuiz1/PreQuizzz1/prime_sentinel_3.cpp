#include <iostream>
using namespace std;

// =====================================================
// The Prime Sentinel III
// =====================================================
// 1. รับชุดตัวเลข N ตัว
// 2. แยกเป็น 2 กลุ่ม: prime กับ non-prime
// 3. เช็คตัวเลขตัวสุดท้าย:
//    - ลงท้ายด้วย 0 → sort prime น้อยไปมาก (ascending)
//    - ไม่ลงท้ายด้วย 0 → sort prime มากไปน้อย (descending)
// 4. non-prime คงลำดับเดิม
// 5. แสดงผล: *** non-prime ก่อน *** แล้วตามด้วย prime
// =====================================================

// ตรวจสอบจำนวนเฉพาะ
bool isPrime(int n) {
  if (n < 2)
    return false;
  if (n == 2)
    return true;
  if (n % 2 == 0)
    return false;
  for (int i = 3; i * i <= n; i += 2) {
    if (n % i == 0)
      return false;
  }
  return true;
}

// --- Merge Sort (ascending) ---
void merge(int arr[], int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  int L[500], R[500];
  for (int i = 0; i < n1; i++)
    L[i] = arr[left + i];
  for (int i = 0; i < n2; i++)
    R[i] = arr[mid + 1 + i];

  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j])
      arr[k++] = L[i++];
    else
      arr[k++] = R[j++];
  }
  while (i < n1)
    arr[k++] = L[i++];
  while (j < n2)
    arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}

// กลับ array (สำหรับ descending)
void reverseArray(int arr[], int n) {
  for (int i = 0; i < n / 2; i++) {
    int temp = arr[i];
    arr[i] = arr[n - 1 - i];
    arr[n - 1 - i] = temp;
  }
}

int main() {
  int n;
  cin >> n;

  int arr[1000];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  // --- Step 1: แยก prime กับ non-prime (แยก 1 ออกมาต่างหาก) ---
  int primes[1000], nonPrimes[1000];
  int pCnt = 0, npCnt = 0;
  int oneCount = 0; // นับจำนวน 1 ที่พบ

  for (int i = 0; i < n; i++) {
    if (isPrime(arr[i])) {
      primes[pCnt++] = arr[i];
    } else {
      if (arr[i] == 1) {
        oneCount++; // เก็บไว้ใส่ท้าย
      } else {
        nonPrimes[npCnt++] = arr[i];
      }
    }
  }

  // --- Step 2: เช็คตัวสุดท้าย ลงท้ายด้วย 0 หรือไม่ ---
  int lastNum = arr[n - 1];
  bool endsWithZero = (lastNum % 10 == 0);

  // --- Step 3: Sort non-prime (ยกเว้น 1) ด้วย Merge Sort ascending ---
  if (npCnt > 0) {
    mergeSort(nonPrimes, 0, npCnt - 1);
  }

  // เพิ่ม 1 ไว้ท้ายสุดของ non-primes
  for (int i = 0; i < oneCount; i++) {
    nonPrimes[npCnt++] = 1;
  }

  // --- Step 4: Sort prime ด้วย Merge Sort ---
  if (pCnt > 0) {
    mergeSort(primes, 0, pCnt - 1); // sort ascending ก่อนเสมอ
  }

  // ถ้าไม่ลงท้ายด้วย 0 → กลับเป็น descending
  if (!endsWithZero) {
    reverseArray(primes, pCnt);
  }

  // --- Step 5: แสดงผล non-prime ก่อน แล้วตามด้วย prime ---
  bool first = true;
  for (int i = 0; i < npCnt; i++) {
    if (!first)
      cout << " ";
    cout << nonPrimes[i];
    first = false;
  }
  for (int i = 0; i < pCnt; i++) {
    if (!first)
      cout << " ";
    cout << primes[i];
    first = false;
  }
  cout << endl;

  return 0;
}
