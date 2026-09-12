#include <stdio.h>

struct Item
{
    int weight;
    int profit;
    float ratio;
};

int main()
{
    struct Item item[100];
    int n, capacity;
    int i, j;

    float totalProfit = 0;
    float fraction;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weight and profit of each item:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &item[i].weight, &item[i].profit);

        item[i].ratio =
            (float)item[i].profit / item[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);


    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (item[j].ratio < item[j + 1].ratio)
            {
                struct Item temp;

                temp = item[j];
                item[j] = item[j + 1];
                item[j + 1] = temp;
            }
        }
    }


    for (i = 0; i < n; i++)
    {
        if (capacity == 0)
            break;

        if (item[i].weight <= capacity)
        {
            capacity = capacity - item[i].weight;

            totalProfit =
                totalProfit + item[i].profit;
        }
        else
        {
            fraction =
                (float)capacity / item[i].weight;

            totalProfit =
                totalProfit +
                item[i].profit * fraction;

            capacity = 0;
        }
    }

    printf("Maximum profit = %.2f\n", totalProfit);

    return 0;
}