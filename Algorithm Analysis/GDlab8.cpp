#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int A[1000];
    
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int MSum = -1000000; 
    int st = 0, en = 0;

    for (int i = 0; i < n; i++) {
        int CSum = 0;
        for (int j = i; j < n; j++) {
            CSum += A[j];
            if (CSum > MSum) {
                MSum = CSum;
                st = i;
                en = j;
            }
        }
    }

    cout << MSum << endl;

    return 0;
}

