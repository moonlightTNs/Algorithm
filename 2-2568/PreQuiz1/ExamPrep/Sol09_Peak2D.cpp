// ข้อ 9: Peak Finding in 2D Array (Divide and Conquer)
// Time: O(N log M)
#include <iostream>
using namespace std;

int grid[1001][1001];
int N, M;

// หาแถวที่มีค่ามากที่สุดในคอลัมน์ col
int findMaxRow(int col) {
  int maxRow = 0;
  for (int i = 1; i < N; i++) {
    if (grid[i][col] > grid[maxRow][col])
      maxRow = i;
  }
  return maxRow;
}

// D&C: ค้นหา peak ในช่วงคอลัมน์ [colL, colR]
void findPeak(int colL, int colR, int &ansRow, int &ansCol) {
  int midCol = (colL + colR) / 2;

  // หาค่ามากที่สุดในคอลัมน์กลาง
  int maxRow = findMaxRow(midCol);

  // เปรียบเทียบกับเพื่อนบ้านซ้าย-ขวา
  int cur = grid[maxRow][midCol];
  int leftVal = (midCol > 0) ? grid[maxRow][midCol - 1] : -1;
  int rightVal = (midCol < M - 1) ? grid[maxRow][midCol + 1] : -1;

  if (cur >= leftVal && cur >= rightVal) {
    // เป็น peak!
    ansRow = maxRow;
    ansCol = midCol;
    return;
  }

  if (leftVal > cur && colL <= midCol - 1) {
    // ไปฝั่งซ้าย
    findPeak(colL, midCol - 1, ansRow, ansCol);
  } else {
    // ไปฝั่งขวา
    findPeak(midCol + 1, colR, ansRow, ansCol);
  }
}

int main() {
  cin >> N >> M;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      cin >> grid[i][j];

  int ansRow, ansCol;
  findPeak(0, M - 1, ansRow, ansCol);

  // Output 1-indexed
  cout << ansRow + 1 << " " << ansCol + 1 << endl;

  return 0;
}
