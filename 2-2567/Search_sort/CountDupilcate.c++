#include <iostream>

using namespace std;

int BNS_F(int a[], int l, int r, int k, int index)
{

    int mid = (l + r) / 2;

    while (l <= r)
    {

        if (k == a[mid])
        {
            index = mid;
            return BNS_F(a, l, mid - 1, k, index);
        }

        if (k > a[mid])
        {
            return BNS_F(a, mid + 1, r, k, index);
        }

        else
        {
            return BNS_F(a, l, mid - 1, k, index);
        }
    }
    return index;
}

int BNS_L(int a[], int l, int r, int k, int index)
{

    int mid = (l + r) / 2;

    while (l <= r)
    {

        if (k == a[mid])
        {
            index = mid;
            return BNS_L(a, mid+1, r, k, index);
        }

        if (k > a[mid])
        {
            return BNS_L(a, mid + 1, r, k, index);
        }

        else
        {
            return BNS_L(a, l, mid - 1, k, index);
        }
    }
    return index;
}

int main()
{

    int n = 11;
    int a[n] = {1, 2, 2, 2, 4, 5, 6, 10, 10, 11, 11};
    // int n = sizeof(a)/sizeof(a[0]) ;

    int target = 2;

    int F = BNS_F(a, 0 , n - 1, target, -1);
    int L = BNS_L(a, 0, n-1 , target ,-1)  ;

    cout << (L-F)+1;
}
