#include <iostream>
using namespace std;

int MaxV = INT_MIN;
int V[100];  // มูลค่าสินค้า 
int W[100];  // น้ำหนักสินค้า 
int k;       // น้ำหนักสูงสุดที่ถุงรับได้
int n;       // จำนวนสินค้า

void knap_print(int x[])
{
    int sum_w = 0;
    int sum_v = 0;

    for (int i = 1; i <= n; i++)
    {
        if (x[i] == 1)
        {
            sum_w += W[i];
            sum_v += V[i];
        }
    }

    if (sum_w <= k)
    {
        if (sum_v > MaxV)
        {
            MaxV = sum_v;
        }
    }
}

void subsetbinary(int x[], int l, int r)
{
    if (l == r)
    {
        knap_print(x);
    }
    else
    {
        x[l + 1] = 1;
        subsetbinary(x, l + 1, r);
        x[l + 1] = 0;
        subsetbinary(x, l + 1, r);
    }
}

int main()
{
    // k (น้ำหนักสูงสุดของถุง)
    cin >> k;
    
    // มูลค่าสินค้า 4 ชิ้น
    n = 4;
    for (int i = 1; i <= n; i++)
    {
        cin >> V[i];
    }
    
    // น้ำหนักสินค้า 4 ชิ้น
    for (int i = 1; i <= n; i++)
    {
        cin >> W[i];
    }

    int x[n + 1];

    subsetbinary(x, 0, n);
    cout << MaxV << endl;

    return 0;
}