#include <iostream>
#include <vector>
#include <algorithm> // สำหรับฟังก์ชัน min

using namespace std;


int C(int i, int j) {
    return (2 * i) + j;
}

// ฟังก์ชัน P(i, j) สำหรับ DP แบบ Top-down
int P(int i, int j) {

    vector<vector<int>> memo(i + 1, vector<int>(j + 1, -1));
    // 1. Base Case (จุดเริ่มต้น / จุดหยุด)
    if (i == 0) return 3 * j;
    if (j == 0) return 2 * i;

    // 2. Memoization: ถ้าเคยคำนวณค่าของ (i, j) ไว้แล้ว ให้ดึงมาตอบได้เลยไม่ต้องคิดซ้ำ!
    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    // 3. ถ้ายังไม่เคยคิด ให้คำนวณตาม Recurrence Relation ทั้ง 3 ทางเลือก
    int sol1 = P(i - 1, j) + 2;
    int sol2 = P(i, j - 1) + 3;
    int sol3 = P(i - 1, j - 1) + C(i, j);

    // 4. หาค่าที่น้อยที่สุด (min) แล้ว "จดลงตาราง (memo)" ก่อนรีเทิร์นกลับไป
    memo[i][j] = min({sol1, sol2, sol3});
    
    return memo[i][j];
}

int main() {
    int n, m;
    
    // รับค่า input n และ m
    if (cin >> n >> m) {
        // กำหนดขนาดตาราง memo เป็น (n+1) x (m+1) เพื่อให้รองรับ index ไปถึง n และ m
        // และกำหนดค่าเริ่มต้นทุกช่องให้เป็น -1

        // เรียกใช้งานฟังก์ชันและพิมพ์ผลลัพธ์
        cout << P(n, m) << "\n";
    }

    return 0;
}