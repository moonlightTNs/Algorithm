// ข้อ 12: Merge K Sorted Arrays (Divide and Conquer)
// Time: O(KM log K)
#include <iostream>
using namespace std;

// เก็บ array ทั้งหมดใน 2D array
// ใช้ buffers สำหรับ merge
int arrays[65][1001];         // K arrays ขนาด M
int bufA[65000], bufB[65000]; // buffers สำหรับเก็บผลลัพธ์
int result[65000];

// Merge 2 sorted arrays เข้าด้วยกัน
int merge2(int a[], int na, int b[], int nb, int out[]) {
  int i = 0, j = 0, k = 0;
  while (i < na && j < nb) {
    if (a[i] <= b[j])
      out[k++] = a[i++];
    else
      out[k++] = b[j++];
  }
  while (i < na)
    out[k++] = a[i++];
  while (j < nb)
    out[k++] = b[j++];
  return k;
}

int main() {
  int K, M;
  cin >> K >> M;

  for (int i = 0; i < K; i++)
    for (int j = 0; j < M; j++)
      cin >> arrays[i][j];

  // Divide and Conquer: merge ทีละคู่
  // ใช้ flat arrays เก็บผลลัพธ์แต่ละ level

  // Level 0: copy แต่ละ array ลง flat structure
  // sizes[i] = ขนาดของ array i ในระดับปัจจุบัน
  // offsets[i] = ตำแหน่งเริ่มต้นของ array i ใน buffer

  int sizes[65];
  int offsets[65];
  int numArrays = K;

  // init: copy ทุก array ลง bufA
  int pos = 0;
  for (int i = 0; i < K; i++) {
    offsets[i] = pos;
    sizes[i] = M;
    for (int j = 0; j < M; j++)
      bufA[pos++] = arrays[i][j];
  }

  // ใช้ pointer สลับ buffer
  bool useA = true; // ข้อมูลอยู่ใน bufA

  while (numArrays > 1) {
    int newNum = 0;
    int newPos = 0;
    int newSizes[65];
    int newOffsets[65];

    int *src = useA ? bufA : bufB;
    int *dst = useA ? bufB : bufA;

    for (int i = 0; i < numArrays; i += 2) {
      if (i + 1 < numArrays) {
        // merge array i และ i+1
        newOffsets[newNum] = newPos;
        int merged = merge2(src + offsets[i], sizes[i], src + offsets[i + 1],
                            sizes[i + 1], dst + newPos);
        newSizes[newNum] = merged;
        newPos += merged;
        newNum++;
      } else {
        // เหลือตัวเดียว → copy ไป
        newOffsets[newNum] = newPos;
        newSizes[newNum] = sizes[i];
        for (int j = 0; j < sizes[i]; j++)
          dst[newPos + j] = src[offsets[i] + j];
        newPos += sizes[i];
        newNum++;
      }
    }

    // update
    numArrays = newNum;
    for (int i = 0; i < numArrays; i++) {
      offsets[i] = newOffsets[i];
      sizes[i] = newSizes[i];
    }
    useA = !useA;
  }

  // ผลลัพธ์อยู่ใน buffer ที่ใช้ล่าสุด
  int *final_buf = useA ? bufA : bufB;
  for (int i = 0; i < sizes[0]; i++) {
    if (i > 0)
      cout << " ";
    cout << final_buf[offsets[0] + i];
  }
  cout << endl;

  return 0;
}
