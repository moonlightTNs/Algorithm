#include<iostream>

using namespace std;

int count = 0;  // global counter

void permute(int x[], int start, int end) {
    if (start == end) {
        bool closeNum = false;
        // ตรวจว่า 1 กับ 3 อยู่ติดกันหรือไม่
        for (int i = 1; i < end; i++) {  // i < end เพราะจะเข้าถึง x[i+1]
            if ((x[i] == 1 && x[i + 1] == 3) || (x[i] == 3 && x[i + 1] == 1)) {
                closeNum = true;
                break;
            }
        }
        
        if (!closeNum) {
            count++;
            for (int i = 1; i <= end; i++) {
                cout << x[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    for (int i = start; i <= end; i++) {
        swap(x[start], x[i]);
        permute(x, start + 1, end);
        swap(x[start], x[i]);
    }
}

int main() {
    int n = 5;
    int x[] = {-1, 1, 2, 3, 4, 5};

    permute(x, 1, n);
    
    cout << "Total permutations (1 and 3 not adjacent): " << count << endl;
    return 0;
}
