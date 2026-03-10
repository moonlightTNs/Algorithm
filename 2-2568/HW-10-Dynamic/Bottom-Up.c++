#include <iostream>
using namespace std;

long long dp[1001];

long long G(int n)
{
    // Base case
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    // Bottom-Up
    for(int i = 3; i <= n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2] - dp[i-3];
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;

    cout << G(n);

    return 0;
}