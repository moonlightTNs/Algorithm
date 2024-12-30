#include <iostream>
using namespace std;

const int MAX_TIME = 100000; // ขอบเขตของเวลา

int main() {
    int n;
    cin >> n;

    // สร้างอาเรย์สำหรับนับจำนวนลูกค้าเข้า-ออกในแต่ละช่วงเวลา
    int timeline[MAX_TIME + 2] = {0};

    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;

        // นับเริ่มต้นที่ช่วงเวลา start
        timeline[start]++;
        // นับสิ้นสุดที่ช่วงเวลาหลังจาก end
        timeline[end + 1]--;
    }

    // คำนวณจำนวนลูกค้าสูงสุดที่อยู่ในร้านในเวลาเดียวกัน
    int max_customers = 0, current_customers = 0;
    int best_start = 0, best_end = 0, temp_start = 0;

    bool in_interval = false; // ติดตามว่ากำลังอยู่ในช่วงเวลาใช้งานหรือไม่

    for (int time = 0; time <= MAX_TIME; time++) {
        current_customers += timeline[time];

        if (current_customers > max_customers) {
            // อัปเดตจำนวนลูกค้าสูงสุด
            max_customers = current_customers;
            best_start = time; // เริ่มช่วงเวลาใหม่
            in_interval = true; // กำลังอยู่ในช่วงเวลา
        } else if (current_customers < max_customers && in_interval) {
            // สิ้นสุดช่วงเวลาที่มีลูกค้ามากที่สุด
            best_end = time - 1;
            in_interval = false; // จบช่วงเวลา
        }
    }

    // แสดงผลลัพธ์
    cout << best_start << " " << best_end << " " << max_customers << endl;

    return 0;
}
