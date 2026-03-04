#include <iostream>
using namespace std;

long long memo[1000];  

long long G(long long n) {

    if (memo[n] != -1)
        return memo[n];

    if (n == 0)
        return memo[n] = 0;

    if (n == 1)
        return memo[n] = 1;

    if (n == 2)
        return memo[n] = 1;

    return memo[n] = G(n-1) + G(n-2) - G(n-3);
}

int main() {

    
    for (int i = 0; i < 1000; i++)
        memo[-i] = -1;

    long long n;
    cin >> n;

    cout << G(n);

    return 0;
}
