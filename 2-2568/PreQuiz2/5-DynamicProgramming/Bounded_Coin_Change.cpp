#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;

const int INF = 1e9;

struct Coin {
  int value;
  int count;
};

// Sort coins by value descending
bool compareCoins(const Coin &a, const Coin &b) { return a.value > b.value; }

int main() {
  int n;
  if (!(cin >> n))
    return 0;

  vector<Coin> coins(n);
  for (int i = 0; i < n; i++)
    cin >> coins[i].value;
  for (int i = 0; i < n; i++)
    cin >> coins[i].count;

  int m;
  cin >> m;

  // เรียงเหรียญจากมากไปน้อย เพื่อให้การเลือกเหรียญใหญ่ถูกพิจารณาก่อน
  sort(coins.begin(), coins.end(), compareCoins);

  // dp[j] เก็บจำนวนเหรียญที่น้อยที่สุดที่ใช้สำหรับยอด j
  vector<int> dp(m + 1, INF);
  // choice[i][j] เก็บ "จำนวนเหรียญชนิดที่ i" ที่ถูกเลือกใช้เพื่อทอนเงินยอด j
  vector<vector<int>> choice(n, vector<int>(m + 1, 0));

  dp[0] = 0;

  for (int i = 0; i < n; i++) {
    // สร้าง new_dp เพื่อแยกคำนวณขั้นปัจจุบันออกจากขั้นเรียนก่อนหน้า
    vector<int> new_dp = dp;
    int v = coins[i].value;
    int c = coins[i].count;

    for (int j = 0; j <= m; j++) {
      if (dp[j] == INF)
        continue; // ถ้ายังไม่เคยมียอด j ให้ข้าม
      // ลองหยิบเหรียญชนิดที่ i จำนวน 1 ถึง c เหรียญ
      for (int k = 1; k <= c; k++) {
        long long next_val = (long long)j + (long long)k * v;
        if (next_val > m)
          break; // ถ้ายอดเกิน m ก็หยุดวงจรได้เลย (ไม่มีประโยชน์)

        // ถ้าการใช้เหรียญนี้ k เหรียญทำให้ได้จำนวนเหรียญรวมน้อยกว่าค่าเดิม
        if (dp[j] + k < new_dp[next_val]) {
          new_dp[next_val] = dp[j] + k;
          choice[i][next_val] = k; // จำไว้ว่าใช้เหรียญชนิด i จำนวน k เหรียญในขั้นตอนนี้
        }
      }
    }
    dp = new_dp; // เลื่อนขั้นจาก new_dp มาเป็น dp ตัวหลัก
  }

  // ส่วนการพิมพ์ผลลัพธ์
  if (dp[m] == INF) {
    cout << "impossible\n";
  } else {
    cout << dp[m] << "\n";
    vector<pair<int, int>> result;
    int current_amount = m;

    // แกะรอยแบบย้อนกลับเพื่อหาว่าใช้เหรียญอะไรไปบ้าง (ย้อนจากชนิดล่างสุดขึ้นมา)
    for (int i = n - 1; i >= 0; i--) {
      int k = choice[i][current_amount];
      if (k > 0) {
        result.push_back({coins[i].value, k});
        current_amount -= k * coins[i].value;
      }
    }

    // เรียงลำดับคำตอบ (มูลค่าเหรียญมากไปน้อย) ตามโจทย์
    sort(result.begin(), result.end(),
         [](const pair<int, int> &a, const pair<int, int> &b) {
           return a.first > b.first;
         });

    // เฉพาะเหรียญที่ถูกใช้งาน
    for (int i = 0; i < result.size(); i++) {
      cout << result[i].first << ":" << result[i].second << "\n";
    }
  }

  return 0;
}
