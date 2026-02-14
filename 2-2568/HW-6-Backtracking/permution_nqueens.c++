#include<iostream>
#include<cmath>

using namespace std;

int count = 0;  // นับจำนวน solution
int n = 4;      // ขนาดกระดาน 4x4

// ตรวจว่า queen ชนกันในแนวทแยงหรือไม่
// x[i] = column ของ queen ใน row i
bool isSafe(int x[], int row) {
    for (int i = 1; i < row; i++) {
        // ตรวจแนวทแยง: ถ้า |row1 - row2| == |col1 - col2| แสดงว่าอยู่แนวทแยงเดียวกัน
        if (abs(x[i] - x[row]) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

// แสดงกระดาน
void printBoard(int x[]) {
    cout << "Solution " << count << ":" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i] == j) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << "Position: ";
    for (int i = 1; i <= n; i++) {
        cout << x[i] << " ";
    }
    cout << endl << endl;
}

void nqueens(int x[], int start, int end) {
    if (start == end) {
        // ตรวจว่า queen ตัวสุดท้ายชนแนวทแยงไหม
        if (isSafe(x, end)) {
            count++;
            printBoard(x);
        }
        return;
    }

    for (int i = start; i <= end; i++) {
        swap(x[start], x[i]);
        // Backtracking: ตรวจก่อนไปต่อ ถ้าไม่ safe ก็ไม่ต้องไปลึกกว่านี้
        if (isSafe(x, start)) {
            nqueens(x, start + 1, end);
        }
        swap(x[start], x[i]);
    }
}

int main() {
    // x[i] = column ของ queen ใน row i
    // ใช้ permutation ของ {1,2,3,4} ทำให้ไม่ต้องตรวจ row และ column ซ้ำ
    int x[] = {-1, 1, 2, 3, 4};

    cout << "=== N-Queens Problem (4x4) ===" << endl << endl;
    
    nqueens(x, 1, n);
    
    cout << "Total solutions: " << count << endl;
    return 0;
}
