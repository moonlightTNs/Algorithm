#include <iostream>
using namespace std;

long long dp[1001][1001];

// ฟังก์ชัน Top-Down DP
long long F(int n, int k)
{
    // STEP 1 : ตรวจสอบเงื่อนไขที่เป็นไปไม่ได้
    if (k < 0 || k > n)
        return 0;

    // STEP 2 : Base Case
    if (k == 0 || k == 1 || k == n)
        return 1;

    // STEP 3 : ตรวจสอบว่าคำนวณไปแล้วหรือยัง (Memoization)
    if (dp[n][k] != -1)
        return dp[n][k];

    // STEP 4 : คำนวณปัญหาย่อย (Recursive)
    dp[n][k] = F(n-1, k) + F(n-1, k-2);

    // STEP 5 : คืนค่าที่เก็บไว้
    return dp[n][k];
}

int main()
{
    int n, k;
    cin >> n >> k;

    if(n < k) {
        cout << 0;
        return 0;
    }
    // STEP 0 : เตรียม array สำหรับเก็บค่าที่คำนวณแล้ว
    for(int i=0;i<=n;i++)
        for(int j=0;j<=k;j++)
            dp[i][j] = -1;

    cout << F(n,k);

    return 0;
}