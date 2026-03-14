#include <iostream>
#include <vector>

using namespace std;

int target = 8;
int minCuts = 1e9 ;
vector<int> wire = {2, 3, 5};

void binaryBack(const vector<int> &x, int idx, int l, int sum)
{
    if (sum == target)
    {
        if (l < minCuts)
        {
            minCuts = l;
        }
        return;
    }

    if (idx >= (int)x.size())
        return;

    if (sum > target || l >= minCuts)
        return;

    // ไม่เลือกเส้นลวด idx
    binaryBack(x, idx + 1, l, sum);
    // เลือกเส้นลวด idx
    binaryBack(x, idx + 1, l + 1, sum + x[idx]);
}

int main()
{
    binaryBack(wire, 0, 0, 0);

    if (minCuts == 1e9)
        cout << -1;
    else
        cout << minCuts;

    return 0;
}
