#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int getbits(int n);
void split(int a[], int n, int k);
int combine(int a[], int k);
int compare_up(const void *a, const void *b);
int compare_down(const void *a, const void *b);
int main(void)
{
    int n1, n2, oldnum = -1, num, size, numbers[size];
    printf("please enter the number:");
    scanf("%d", &num);
    while (num != oldnum)
    {
        oldnum = num;
        size = getbits(num);
        split(numbers, num, size); //分解
        qsort(numbers, size, sizeof numbers[0], compare_down);
        n1 = combine(numbers, size);
        qsort(numbers, size, sizeof numbers[0], compare_up);
        n2 = combine(numbers, size);
        num = n1 - n2;
    }
    printf("\nthe number is %d", num);
    return 0;
}
int compare_up(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b); //前小后大，ab升序
}
int compare_down(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a); //前小后大，ab降序
}
int getbits(int num)
{
    int counter;
    for (counter = 0; num != 0; counter++)
        num /= 10;
    return counter;
}
void split(int *ptr, int num, int size)
{
    int counter;
    for (counter = 0; counter < size; counter++, num /= 10)
        *(ptr + counter) = num % 10;
}
int combine(int *ptr, int size)
{
    int sum = 0, counter;
    for (counter = size - 1; counter > -1; counter--)
        sum += (*(ptr + counter)) * ((int)(pow(10, size - 1 - counter)));
    return sum;
}