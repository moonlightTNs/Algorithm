#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int n, max_sum = 0;
    cin >> n ;
    int a[n + 1] = {};

    if (n < 0 || n >= 1000)
    {
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int current_sum = 0, start = 0, end = 0, temp_start = 0;
    for(int i = 0; i < n; i++){
        if (current_sum + a[i] > a[i]) {
            current_sum += a[i];
        } else {
            current_sum = a[i];
            temp_start = i;
        }

        if (current_sum > max_sum) {
            max_sum = current_sum;
            start = temp_start;
            end = i;
        }
    }

    cout << "Maximum contiguous subsequence sum is " << max_sum << endl;
    cout << "Subarray with maximum sum: ";
    for (int i = start; i <= end; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}