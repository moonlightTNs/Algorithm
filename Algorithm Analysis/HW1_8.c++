#include <iostream>
using namespace std;

int main()
{
    int n;

    cin >> n;

    int A[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }

    
    int maxSum = A[0];                
    int startIndex = 0, endIndex = 0; 

    for (int i = 0; i < n; ++i)
    {                       
        int currentSum = 0; 
        for (int j = i; j < n; ++j)
        {                      
            currentSum += A[j];
            if (currentSum > maxSum)
            { 
                maxSum = currentSum;
                startIndex = i;
                endIndex = j;
            }
        }
    }

    
    cout << "Maximum contiguous subsequence sum is " << maxSum << endl;
    cout << "The subsequence is: ";
    for (int i = startIndex; i <= endIndex; ++i)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
