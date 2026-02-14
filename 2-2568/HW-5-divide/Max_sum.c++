#include<iostream>  

using namespace std;

// Find max subarray sum that crosses the midpoint
int maxCrossingSum(int a[], int left, int mid, int right, int &startIdx, int &endIdx) {
    int sum = 0;
    int leftSum = INT_MIN;
    startIdx = mid;
    // Include elements on left of mid
    for (int i = mid; i >= left; i--) {
        sum += a[i];
        if (sum > leftSum) {
            leftSum = sum;
            startIdx = i;
        }
    }

    sum = 0;
    int rightSum = INT_MIN;
    endIdx = mid + 1;
    // Include elements on right of mid
    for (int i = mid + 1; i <= right; i++) {
        sum += a[i];
        if (sum > rightSum) {
            rightSum = sum;
            endIdx = i;
        }
    }

    return leftSum + rightSum;
}

// Recursive function to find max subarray sum
int maxSubArray(int a[], int left, int right, int &maxStartIdx, int &maxEndIdx) {
    if (left == right) {
        maxStartIdx = left;
        maxEndIdx = right;
        return a[left];
    }

    int mid = (left + right) / 2;

    int leftStartIdx, leftEndIdx, rightStartIdx, rightEndIdx, crossStartIdx, crossEndIdx;
    int leftMax = maxSubArray(a, left, mid, leftStartIdx, leftEndIdx);
    int rightMax = maxSubArray(a, mid + 1, right, rightStartIdx, rightEndIdx);
    int crossMax = maxCrossingSum(a, left, mid, right, crossStartIdx, crossEndIdx);

    if (leftMax >= rightMax && leftMax >= crossMax) {
        maxStartIdx = leftStartIdx;
        maxEndIdx = leftEndIdx;
        return leftMax;
    } else if (rightMax >= leftMax && rightMax >= crossMax) {
        maxStartIdx = rightStartIdx;
        maxEndIdx = rightEndIdx;
        return rightMax;
    } else {
        maxStartIdx = crossStartIdx;
        maxEndIdx = crossEndIdx;
        return crossMax;
    }
}

int main() {
    int a[] = {16, -25, 2, -54, 36, 9, -12, 66};
    int n = sizeof(a) / sizeof(a[0]);

    int maxStartIdx, maxEndIdx;
    int maxSum = maxSubArray(a, 0, n - 1, maxStartIdx, maxEndIdx);
    cout << "Max Sum: " << maxSum << endl;
    cout << "Start Index: " << maxStartIdx+1 << endl;
    cout << "End Index: " << maxEndIdx+1 << endl;
    return 0;
}