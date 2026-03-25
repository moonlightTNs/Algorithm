#include <iostream>
#include <vector>

using namespace std;

// ฟังก์ชัน DP สำหรับคำนวณจำนวนวิธีแลกเหรียญ
// รับค่า n (จำนวนเงินเป้าหมาย) และ coins (รายการมูลค่าเหรียญ)
long long countWays(int n, const vector<int>& coins) {
    // สร้างตาราง DP ขนาด n + 1 และกำหนดค่าเริ่มต้นเป็น 0
    // ใช้ long long เพื่อป้องกันตัวเลขล้น (Overflow) เมื่อจำนวนวิธีมีมหาศาล
    vector<long long> dp(n + 1, 0);
    
    // Base case: แลกเงิน 0 บาท ทำได้ 1 วิธี (คือไม่หยิบอะไรเลย)
    dp[0] = 1;

    // หัวใจของ DP: วนลูปเหรียญแต่ละชนิด
    for (int i = 0; i < coins.size(); ++i) {
        int coin = coins[i];
        
        // อัปเดตจำนวนวิธีของแต่ละจำนวนเงิน (ตั้งแต่มูลค่าเหรียญนั้น ไปจนถึง n)
        for (int j = coin; j <= n; ++j) {
            dp[j] = dp[j] + dp[j - coin];
        }
    }

    // คืนค่าจำนวนวิธีทั้งหมดสำหรับจำนวนเงินเป้าหมาย n บาท
    return dp[n];
}

int main() {
    // เพิ่มความเร็วในการรับ-ส่งข้อมูล (I/O Optimization)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    
    // รับค่า n (เงินเป้าหมาย) และ k (จำนวนชนิดเหรียญ)
    if (!(cin >> n >> k)) return 0;

    // รับมูลค่าเหรียญ
    vector<int> coins(k);
    for (int i = 0; i < k; ++i) {
        cin >> coins[i];
    }

    // เรียกใช้งานฟังก์ชัน DP และเก็บผลลัพธ์
    long long ans = countWays(n, coins);

    // แสดงผลลัพธ์
    cout << ans << "\n";

    return 0;
}