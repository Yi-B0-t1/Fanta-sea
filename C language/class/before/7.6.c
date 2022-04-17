#include <stdio.h>
#define SIZE 10
int num[SIZE];
void process(int *ptr, int n);
void output(const int *ptr, int n);
int *input(void)
{
    int i;
    // printf("please enter 10 int numbers:");
    for (i = 0; i < 10; i++)
        scanf("%d", &num[i]);
    return num;
}
int main(void)
{
    int *num = input();
    // printf("here is your array:");
    output(num, SIZE);
    process(num, SIZE);
    // printf("\nhere is your array processed:");
    output(num, SIZE);
    return 0;
}
void swap(int *a, int *b);
void process(int *ptr, int n)
{
    int min, max, counter;
    min = max = *ptr;
    for (counter = 1; counter < n; counter++)
    {
        if (*(ptr + counter) > max)
            max = *(ptr + counter);
        if (*(ptr + counter) < min)
            min = *(ptr + counter);
    }
    for (counter = 0; counter < n; counter++)
    {
        if (*(ptr + counter) == max)
            swap((ptr + counter), (ptr + SIZE - 1));
        if (*(ptr + counter) == min)
            swap((ptr + counter), ptr);
    }
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void output(const int *ptr, int n)
{
    int counter;
    for (counter = 0; counter < n; counter++)
        printf("%d ", *(ptr + counter));
}