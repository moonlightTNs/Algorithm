#include <iostream>
using namespace std;

int maxItems(int n, int k, int price[])
{
    int dp[1001];

    // initialize
    for(int i=0;i<=k;i++)
        dp[i] = -1;

    dp[0] = 0;

    for(int i=0;i<n;i++) // loop for each item
    {
        for(int j=k;j>=price[i];j--) // loop for each price from k to price[i]
        {
            if(dp[j-price[i]] != -1)
            {
                dp[j] = max(dp[j], dp[j-price[i]] + 1);
            }
        }
    }

    return dp[k];
}

int main()
{
    int n,k;
    cin >> n >> k;

    int price[101];

    for(int i=0;i<n;i++)
        cin >> price[i];

    cout << maxItems(n,k,price);

    return 0;
}