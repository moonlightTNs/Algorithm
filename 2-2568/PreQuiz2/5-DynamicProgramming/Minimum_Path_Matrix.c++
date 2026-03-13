#include <climits>
#include <iostream>

using namespace std;

int cost[51][51];
int dp[51][51];
int r1, c1; // start position (x1, y1)

int S(int i, int j) {
  if (i == r1 && j == c1) // ถึงจุดเริ่มต้น (x1, y1)
    return cost[r1][c1];

  if (dp[i][j] != -1)
    return dp[i][j];

  int up = INT_MAX;
  int left = INT_MAX;

  if (i > r1) // ยังไม่ถึงแถวเริ่มต้น
    up = S(i - 1, j);

  if (j > c1) // ยังไม่ถึงคอลัมน์เริ่มต้น
    left = S(i, j - 1);

  dp[i][j] = min(up, left) + cost[i][j];

  return dp[i][j];
}

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> cost[i][j];

  int x1, y1, x2, y2; // x1,y1 = เริ่มต้น, x2,y2 = สิ้นสุด
  cin >> x1 >> y1 >> x2 >> y2;
  r1 = x1;
  c1 = y1;

  for (int i = 0; i < 51; i++)
    for (int j = 0; j < 51; j++)
      dp[i][j] = -1;

  cout << S(x2, y2); // หา min cost จาก (x1,y1) ถึง (x2,y2)
}
