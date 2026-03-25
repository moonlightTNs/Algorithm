#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// สร้างโครงสร้างข้อมูลสำหรับเก็บเวลาเริ่มและเวลาจบของแต่ละกิจกรรม
struct Activity {
    int start;
    int end;
};

// ฟังก์ชันสำหรับกำหนดเงื่อนไขการเรียงลำดับ (Sort)
// เราต้องการเรียงจาก "เวลาจบ (end)" น้อยไปมาก
bool compareActivity(Activity a, Activity b) {
    if (a.end == b.end) {
        return a.start < b.start; // ถ้าจบพร้อมกัน ให้เอาอันที่เริ่มก่อนขึ้นก่อน
    }
    return a.end < b.end;
}

int main() {

    int n;
    cin >> n;

    vector<Activity> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].start >> arr[i].end;
    }

    // 1. เรียงลำดับกิจกรรมตามเวลาจบ จากน้อยไปมาก
    sort(arr.begin(), arr.end(), compareActivity);

    // 2. เลือกกิจกรรมแบบ Greedy
    int count = 0;
    int last_end_time = -1; // เก็บเวลาจบของกิจกรรมล่าสุดที่เลือกไป (เริ่มต้นให้เป็น -1)

    for (int i = 0; i < n; i++) {
        // ถ้าเวลาเริ่มของกิจกรรมนี้ มากกว่าหรือเท่ากับ เวลาจบของกิจกรรมล่าสุดที่เลือกไป
        if (arr[i].start >= last_end_time) {
            count++; // เลือกกิจกรรมนี้
            last_end_time = arr[i].end; // อัปเดตเวลาจบเป็นของกิจกรรมนี้
        }
    }

    // 3. แสดงผลจำนวนกิจกรรมที่มากที่สุดที่เข้าร่วมได้
    cout << count << "\n";

    return 0;
}