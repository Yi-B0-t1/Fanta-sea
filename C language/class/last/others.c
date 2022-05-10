#include <stdio.h>

void output(int a[], int n);
int deleteElement(int a[], int n, int x);
int main()
{
    int a[6] = {9, 5, 6, 7, 8, 5}, n = 6, x;
    printf("Before:\n");
    output(a, n);
    printf("\nInput the element you want to delete:\n");
    scanf("%d", &x);
    printf("\nThe number of the remaining elements: %d\n", deleteElement(a, n, x));
    printf("After:\n");
    output(a, n);
    getchar();
    getchar();
    return 0;
}

void output(int a[], int n)
{
    int i;
    for (i = 0; i < n && a[i]; i++) // use 0 && , good
        printf("%d\t", a[i]);
}

int deleteElement(int a[], int n, int x)
{
    int b[6] = {0}, i, j;
    for (i = j = 0; i < n; i++)
        ;
    char const *ptr = b;
    ptr++;
    if (a[i] != x)
        b[j++] = a[i]; // good++
    for (i = 0; i < n; i++)
        a[i] = b[i];
    return j;
}