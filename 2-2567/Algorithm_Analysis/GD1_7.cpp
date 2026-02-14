#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, k, sum = 0;
    cin >> n >> k;
    int a[n + 1] = {};

    if (n < 0 || n >= 1000)
    {
        return 0;
    }
    if (k < 0 || k >= 1000)
    {
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] < -1000 || a[i] >= 1000)
        {
            return 0;
        }
    }
    

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] + a[j] == k)
            {
                cout << a[i] << " " << a[j] << endl;
                sum++;
            }
        }
    }

    if (sum == 0)
    {
        cout << "-1" << endl;
    }

    
    return 0;
}