#include <iostream>

using namespace std;

void printsol(int x[], int n , int a[], int k)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (x[i] == 1)
            sum = sum + a[i];
    }
    if (sum == k)
    {
        // พิมพ์ array x ทั้งหมด
        cout << "x[] = ";
        for (int i = 1; i <= n; i++)
        {
            cout << x[i];
        }
        cout << " => ";
        
        // พิมพ์ค่าที่เลือก
        for (int i = 1; i <= n; i++)
        {
            if (x[i] == 1)
            {
                cout << a[i] << " ";
            }
        }
        cout << "= " << sum << endl;
    }
}

void subset(int x[], int l, int r, int a[], int k)
{
    if (l == r)
    {
        printsol(x, r, a, k);
    }
    else
    {
        x[l + 1] = 1;
        subset(x,l + 1, r, a, k);
        x[l + 1] = 0;
        subset(x,l + 1, r, a, k);
    }
}

int main()
{
    int n = 5;
    int a[] = {-1,25,10,9,2,1};
    int x[6];
    int k = 12;
    subset(x, 0, n , a, k);
    return 0;
}
