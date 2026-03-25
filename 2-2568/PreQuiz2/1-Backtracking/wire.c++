#include <iostream>
#include <climits>
using namespace std;

int _min = INT_MAX;

void subset_index(int total, int x[], int idx, int start, int L, int n) {
    // Base case: ได้ความยาวพอดี
    if (total == L) {
        if (idx < _min) {
            _min = idx;
        }
        return;
    }
    // Pruning: ถ้าเกินแล้วไม่ต้องลองต่อ
    if (total > L) return;
    // Pruning: ถ้าจำนวนชิ้นปัจจุบันไม่ดีกว่าคำตอบที่มีอยู่แล้ว
    if (idx >= _min) return;
    // ลองเลือกสายไฟแบบ index ไม่ลดลง เพื่อตัดเคสลำดับซ้ำ เช่น 2+3 กับ 3+2
    for (int i = start; i < n; i++) {
        subset_index(total + x[i], x, idx + 1, i, L, n);
    }
}

int main() {
    int L = 0;
    int n = 0;
    cin >> L >> n;
    int x[n+1];

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    subset_index(0, x, 0, 0, L, n);

    if (_min == INT_MAX) {
        cout << -1 << endl;
        cout << "ไม่สามารถต่อสายให้ได้ความยาว " << L << endl;
        return 0;
    }
 
    cout << _min << endl;

    return 0;
}