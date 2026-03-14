#include <iostream>
#include <vector>

using namespace std;

int n = 4;
int k;
int MaxV = 0;
vector<int> Value(n );
vector<int> Weight(n);

// void print(const vector<int> &x, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         cout << x[i] << " ";
//     }
//     cout << endl;
// }

void backtrack(vector<int> &x, int idx, int currentW, int currentV)
{
    if (currentW > k)
    {
        return;
    }

    if (idx == n)
    {
        if (currentV > MaxV)
        {
            MaxV = currentV;
        }
        return;
    }

    x[idx] = 0;
    backtrack(x, idx + 1, currentW, currentV);

    x[idx] = 1;
    backtrack(x, idx + 1, currentW + Weight[idx], currentV + Value[idx]);
}

int main()
{

    cin >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> Value[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> Weight[i];
    }

    vector<int> sol(n, 0);

    backtrack(sol, 0, 0, 0);

    cout << MaxV;
}