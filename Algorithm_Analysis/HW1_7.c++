#include <iostream>
using namespace std;

int main() {
    // กำหนดอาเรย์และจำนวนสมาชิก
    int A[] = {5, 15, -30, 10, -5, 40, 10};
    int n = sizeof(A) / sizeof(A[0]); // คำนวณขนาดของอาเรย์
    int x = 20; // ค่าเป้าหมาย

    // หาและแสดงคู่ที่ผลรวมเท่ากับ x
    cout << "Pairs with sum " << x << " are:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (A[i] + A[j] == x) {
                cout << "{" << A[i] << ", " << A[j] << "}" << endl;
            }
        }
    }

    return 0;
}
