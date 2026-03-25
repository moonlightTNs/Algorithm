#include <iostream>
#include <vector>
#include <algorithm> // สำหรับฟังก์ชัน min

using namespace std;

const int INF = 1e9; // กำหนดค่าอนันต์ แทนความหมายว่า "แลกไม่ได้"

// ฟังก์ชัน DP หาจำนวนเหรียญที่น้อยที่สุด
int minCoins(int amount, const vector<int>& coins) {
    // สร้างตาราง dp ขนาด amount + 1 
    // dp[i] หมายถึง "จำนวนเหรียญน้อยที่สุดที่ใช้แลกเงิน i บาท"
    // เริ่มต้นเซ็ตทุกช่องให้เป็น INF (สมมติว่าแลกไม่ได้ไว้ก่อน)
    vector<int> dp(amount + 1, INF);

    // Base Case: แลกเงิน 0 บาท ใช้ 0 เหรียญ
    dp[0] = 0;

    // ลูปหาจำนวนเหรียญน้อยสุด ตั้งแต่เงิน 1 บาท ไปจนถึงเป้าหมาย (amount)
    for (int i = 1; i <= amount; ++i) {
        // ลองหยิบเหรียญแต่ละชนิดที่มี
        for (int j = 0; j < coins.size(); ++j) {
            int coin = coins[j];
            
            // ถ้ามูลค่าเหรียญ ไม่เกิน จำนวนเงินที่กำลังหา (แปลว่าใส่เหรียญนี้ได้)
            if (i >= coin) {
                // อัปเดตช่อง dp[i] ให้เป็นค่าที่น้อยที่สุดระหว่าง:
                // 1. ค่าเดิมที่เคยหาได้ (dp[i])
                // 2. ถ้าหยิบเหรียญนี้ 1 เหรียญ แล้วบวกกับจำนวนเหรียญของเงินที่เหลือ (dp[i - coin] + 1)
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    // ถ้า dp[amount] ยังเป็น INF แปลว่าไม่มีวิธีทอนเงินจำนวนนี้ได้เลย ให้คืนค่า -1
    if (dp[amount] == INF) {
        return -1; 
    }
    
    // คืนค่าจำนวนเหรียญที่น้อยที่สุด
    return dp[amount];
}

int main() {
    int amount;
    int k;

    // รับจำนวนเงินที่ต้องการแลก (เช่น 6)
    cin >> amount;
    
    // รับจำนวนชนิดของเหรียญ (เช่น 3)
    cin >> k;

    // รับมูลค่าเหรียญ (เช่น 1 3 4)
    vector<int> coins(k);
    for (int i = 0; i < k; ++i) {
        cin >> coins[i];
    }

    // เรียกใช้งานฟังก์ชันและพิมพ์คำตอบ
    int ans = minCoins(amount, coins);
    cout << ans << "\n";

    return 0;
}