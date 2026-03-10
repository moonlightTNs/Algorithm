#include <iostream>
using namespace std;

int dp[101][101];

int C(int i,int j)
{
    return 2*i + j;
}

int P(int i,int j)
{
    if(i==0)
        return 3*j;

    if(j==0)
        return 2*i;

    if(dp[i][j] != -1)
        return dp[i][j];

    int a = P(i-1,j) + 2;
    int b = P(i,j-1) + 3;
    int c = P(i-1,j-1) + C(i,j);

    dp[i][j] = min(a , min(b,c));

    return dp[i][j];
}

int main()
{
    int n,m;
    cin >> n >> m;

    for(int i=0;i<=100;i++)
        for(int j=0;j<=100;j++)
            dp[i][j] = -1;

    cout << P(n,m);
}