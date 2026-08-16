#include <stdio.h>

void sortarr(int a[], int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, i, k;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the value of k: ");
    scanf("%d", &k);

    if (k < 1 || k > n) {
        printf("Invalid value of k");
        return 0;
    }

    sortarr(a, n);

    printf("The %dth smallest element is: %d", k, a[k - 1]);

    return 0;
}
