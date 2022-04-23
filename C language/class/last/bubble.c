#include <stdio.h>
#define N 6
void bubble_sort(int a[], int n)
{
    int i, j, t;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++)
            if (a[j] > a[j + 1])
                t = a[j], a[j] = a[j + 1], a[j + 1] = t;
}
int main(void)
{
    int a[N], i;
    printf("please input %d numbers:\n", N);
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);
    bubble_sort(a, N);
    printf("sorted:\n");
    for (i = 0; i < N; i++)
        printf("%d\t", a[i]);
    putchar('\n');
    return 0;
}