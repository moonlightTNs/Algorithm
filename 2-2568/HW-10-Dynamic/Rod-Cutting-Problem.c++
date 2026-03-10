#include <iostream>
using namespace std;

int rodCutting(int n, int price[])
{
    int dp[1001];
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        dp[i] = 0;
        for (int j = 1; j <= i; j++)
        {
            dp[i] = max(dp[i],price[j] + dp[i - j]);
        }
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;

    int price[1001];
    for (int i = 1; i <= n; i++)
    {
        cin >> price[i];
    }

    cout << rodCutting(n, price);
}