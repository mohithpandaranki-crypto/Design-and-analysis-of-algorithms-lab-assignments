#include <stdio.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int maxCrossingSum(int a[], int low, int mid, int high)
{
    int leftSum = -999999;
    int rightSum = -999999;
    int sum = 0;
    int i;

    for (i = mid; i >= low; i--)
    {
        sum = sum + a[i];

        if (sum > leftSum)
            leftSum = sum;
    }

    sum = 0;

    for (i = mid + 1; i <= high; i++)
    {
        sum = sum + a[i];

        if (sum > rightSum)
            rightSum = sum;
    }

    return leftSum + rightSum;
}

int maxSubarray(int a[], int low, int high)
{
    int mid;
    int leftSum, rightSum, crossSum;

    if (low == high)
        return a[low];

    mid = (low + high) / 2;

    leftSum = maxSubarray(a, low, mid);

    rightSum = maxSubarray(a, mid + 1, high);

    crossSum = maxCrossingSum(a, low, mid, high);

    return max(max(leftSum, rightSum), crossSum);
}

int main()
{
    int a[100];
    int n, i;
    int result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    result = maxSubarray(a, 0, n - 1);

    printf("Maximum subarray sum = %d\n", result);

    return 0;
}