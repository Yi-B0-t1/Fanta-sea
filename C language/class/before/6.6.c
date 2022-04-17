#include <stdio.h>
#define condition i == num[0] * num[0] * num[0] + num[1] * num[1] * num[1] + num[2] * num[2] * num[2]
#define everyline_word 8
int main()
{
    int a, b, c, i;
    int num[3];
    int count = 0;    //四位数的个数
    int oneline = -1; //换行计数器
    for (a = 1; a <= 9; a++)
    {
        for (b = 0; b <= 9; b++)
        {
            for (c = 0; c <= 9; c++)
            {
                i = a * 100 + b * 10 + c;
                num[0] = i % 10;                             //个位数
                num[1] = (i % 100 - num[0]) / 10;            //十位数
                num[2] = (i % 1000 - num[1] - num[0]) / 100; //百位数
                if (condition)
                { //对每一个3位数进行判断，若符合，使计数器加1
                    count++, oneline++;
                    (0 == oneline % everyline_word) ? (printf("\n%d\t", i)) : (printf("%d\t", i));
                }
            }
        }
    }
    return 0;
}