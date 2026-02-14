#include<iostream>

using namespace std;

int n;
int chair[15];      
bool used[15];      
int count_ways = 0;

// ตรวจสอบว่าเด็กคนที่ 1 และ 2 นั่งติดกันหรือไม่
bool isValid() {
    int pos1 = -1, pos2 = -1;
    for (int i = 1; i <= n; i++) {
        if (chair[i] == 1) pos1 = i;
        if (chair[i] == 2) pos2 = i;
    }
    // ตรวจสอบว่าตำแหน่งห่างกัน 1 หรือไม่ (นั่งติดกัน)
    return (pos1 != -1 && pos2 != -1 && abs(pos1 - pos2) == 1);
}

// Backtracking function
void chair(int pos) {
    // ถ้าจัดครบทุกเก้าอี้แล้ว
    if (pos > n) {
        // ตรวจสอบเงื่อนไขว่าเด็กคนที่ 1 และ 2 นั่งติดกัน
        if (isValid()) {
            count_ways++;
        }
        return;
    }
    
    // ลองจัดเด็กแต่ละคนลงเก้าอี้ตำแหน่ง pos
    for (int child = 1; child <= n; child++) {
        if (!used[child]) {
            // เลือกเด็กคนนี้
            chair[pos] = child;
            used[child] = true;
            
            // ไปจัดเก้าอี้ตัวถัดไป
            chair(pos + 1);
            
            // ยกเลิกการเลือก (backtrack)
            chair[pos] = 0;
            used[child] = false;
        }
    }
}

int main() {
    cin >> n;
    
    if (n < 2 || n > 10) {
        cout << "Invalid input: n must be between 2 and 10" << endl;
        return 1;
    }
    
    for (int i = 0; i <= n; i++) {
        used[i] = false;
        chair[i] = 0;
    }
    
    count_ways = 0;
    chair(1);  // เริ่มจัดเก้าอี้ตัวที่ 1
    
    cout << count_ways << endl;
    
    return 0;
}
