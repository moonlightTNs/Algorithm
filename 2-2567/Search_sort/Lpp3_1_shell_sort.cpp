#include <bits/stdc++.h>
using namespace std;

bool prime_Num(int num)
{
    if (num <= 1)
        return false;
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

void shell(int arr[], int n)
{
    int prime_arr[n];
    prime_arr[0] = 1;
    int prime_arr_size = 1;
    for (int i = 2; i < n; i++)
    {
        if (prime_Num(i))
        {
            prime_arr[prime_arr_size] = i;
            prime_arr_size++;
        }
    }

    int i, k, j, temp;
    for (k = prime_arr_size - 1; k >= 0; k--)
    {
        int gap = prime_arr[k];
        for (i = gap; i < n; i++)
        {
            temp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }

        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    if (n <= 0)
    {
        return 0;
    }

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    shell(arr, n);
}
