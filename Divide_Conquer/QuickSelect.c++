#include <stdio.h>

int arr[] = {1, 5, 10, 4, 8, 2, 6, 9, 20};
int k = 4;
int n = sizeof(arr) / sizeof(arr[0]);

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int l, int r)
{
    int mid = l + (r - l) / 2;

    // Median-of-three pivot selection
    if (arr[mid] < arr[l])
    {
        int temp = arr[mid];
        arr[mid] = arr[l];
        arr[l] = temp;
    }
    if (arr[r] < arr[l])
    {
        int temp = arr[r];
        arr[r] = arr[l];
        arr[l] = temp;
    }
    if (arr[mid] < arr[r])
    {
        int temp = arr[mid];
        arr[mid] = arr[r];
        arr[r] = temp;
    }

    int pivot = arr[r];
    int i = l - 1;

    for (int j = l; j < r; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap arr[i + 1] and arr[r] (pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = temp;

    // Print array after partition
    printf("After partition (pivot=%d): ", pivot);
    printArray(arr, n);

    return i + 1;
}

// ฟังก์ชัน Quick Select
int quickSelect(int low, int high, int k)
{
    if (low == high)
    {
        return arr[low];
    }

    int p = partition(low, high);

    if (p == k - 1)
    { // case k = Pivot position
        return arr[p];
    }
    else if (p > k - 1)
    { // case k in L
        return quickSelect(low, p - 1, k);
    }
    else
    { // case k in R
        return quickSelect(p + 1, high, k);
    }
}

int main()
{
    printf("K element: %d\n", quickSelect(0, n - 1, k));
    return 0;
}
