#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int xi[500], xj[500];

    for (int i = 0; i < n; i++) {
        cin >> xi[i] >> xj[i];
    }

    int xa, xb;
    cin >> xa >> xb;

    // เรียงตาม xi จากน้อยไปมาก (Bubble Sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (xi[j] > xi[j + 1] || 
               (xi[j] == xi[j + 1] && xj[j] > xj[j + 1])) {
                swap(xi[j], xi[j + 1]);
                swap(xj[j], xj[j + 1]);
            }
        }
    }

    int current = xa;
    int count = 0;

    int ans_xi[500], ans_xj[500];

    int i = 0;

    while (current < xb) {
        int maxEnd = current;
        int chosen = -1;

        // หาเส้นที่ xi <= current และ xj มากที่สุด
        while (i < n && xi[i] <= current) {
            if (xj[i] > maxEnd) {
                maxEnd = xj[i];
                chosen = i;
            }
            i++;
        }

        if (chosen == -1) {
            cout << "0\n"; // ไม่สามารถครอบคลุมได้
            return 0;
        }

        ans_xi[count] = xi[chosen];
        ans_xj[count] = xj[chosen];
        count++;

        current = maxEnd;
    }

    // เรียงคำตอบตาม xi และ xj จากน้อยไปมาก
    for (int a = 0; a < count - 1; a++) {
        for (int b = 0; b < count - a - 1; b++) {
            if (ans_xi[b] > ans_xi[b + 1] ||
               (ans_xi[b] == ans_xi[b + 1] && ans_xj[b] > ans_xj[b + 1])) {
                swap(ans_xi[b], ans_xi[b + 1]);
                swap(ans_xj[b], ans_xj[b + 1]);
            }
        }
    }

    cout << count << endl;
    for (int k = 0; k < count; k++) {
        cout << ans_xi[k] << " " << ans_xj[k] << endl;
    }

    return 0;
}
