#include <iostream>
using namespace std;

long long path(int n,int m)
{
    long long dp[51][51];

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==1 || j==1)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    return dp[n][m];
}

int main()
{
    int n,m;
    cin >> n >> m;

    //2<= n,m <= 50
    if(n < 2 || n > 50 || m < 2 || m > 50) {
        cout << 0;
        return 0;
    }

    cout << path(n,m);

    return 0;
}