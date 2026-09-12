#include <stdio.h>

int a[100];

void minmax(int low, int high, int *min, int *max)
{
    int min1, max1, min2, max2;
    int mid;

    if (low == high)
    {
        *min = a[low];
        *max = a[low];
    }
    else if (low == high - 1)
    {
        if (a[low] < a[high])
        {
            *min = a[low];
            *max = a[high];
        }
        else
        {
            *min = a[high];
            *max = a[low];
        }
    }
    else
    {
        mid = (low + high) / 2;

        minmax(low, mid, &min1, &max1);
        minmax(mid + 1, high, &min2, &max2);

        if (min1 < min2)
        {
            *min = min1;
        }
        else
        {
            *min = min2;
        }

        if (max1 > max2)
        {
            *max = max1;
        }
        else
        {
            *max = max2;
        }
    }
}

int main()
{
    int n;
    int min, max;
    int i;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    minmax(0, n - 1, &min, &max);

    printf("The value of min and max in this array is: %d %d",
           min, max);

    return 0;
}
