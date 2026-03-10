#include <iostream>
using namespace std;

long long coinChange(int n, int k, int coin[])
{
    long long dp[100001];

    for (int i = 0; i <= n; i++)
    {
        dp[i] = 0;
    }

    dp[0] = 1;

    for (int i = 0; i < k; i++)
    {
        for (int j = coin[i]; j <= n; j++)
        {
            dp[j] += dp[j - coin[i]];
        }
    }

    return dp[n];
}

int main()
{
    int n, k;
    cin >> n;
    cin >> k;
    int coin[5001];

    for (int i = 0; i < k; i++)
    {
        cin >> coin[i];
    }
    cout << coinChange(n, k, coin);
}