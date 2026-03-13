#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main() {
  int n, m;
  while (cin >> n >> m) {
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
      cin >> grid[i];
    }

    // dp[i][j] เก็บความยาวด้านของสี่เหลี่ยมจัตุรัสที่ใหญ่ที่สุดที่มุมขวาล่างอยู่ที่ (i-1, j-1)
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int maxSize = 0;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (grid[i - 1][j - 1] == '#') {
          // หาความยาวที่สั้นที่สุดจาก 3 ด้านรอบๆ แล้วบวก 1
          dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
          if (dp[i][j] > maxSize) {
            maxSize = dp[i][j];
          }
        }
      }
    }

    if (maxSize == 0) {
      cout << 0 << " " << 0 << endl;
    } else {
      // นับจำนวนสี่เหลี่ยมจัตุรัสที่มีขนาด maxSize
      int count = 0;
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          if (dp[i][j] == maxSize) {
            count++;
          }
        }
      }
      cout << maxSize * maxSize << " " << count << endl;
    }
  }

  return 0;
}
