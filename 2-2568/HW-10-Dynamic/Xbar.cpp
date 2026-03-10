#include <iostream>
using namespace std;

double Xbar(int x[], int n, int newV) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += x[i];
    }

    double newXbar = (sum + newV) / (n + 1);
    return newXbar; 
}

int main() {
    int x[] = {4,5,12,7,8};
    int n = sizeof(x) / sizeof(x[0]);

    double s = Xbar(x, n, 12);
    cout << s;

    return 0;
}
