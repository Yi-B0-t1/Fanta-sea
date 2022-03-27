#include <stdio.h>
int main()
{
    int num[4];                    //用于存放四位数字的数组
    int i;                         //用于构建所有数的变量
    int count = 0;                 //四位数的个数
    int oneline = -1;              //换行计数器
    for (i = 1000; i <= 9999; i++) //从1000开始构建所有四位数
    {
        num[0] = i % 10;                                           //个位数
        num[1] = (i % 100 - num[0]) / 10;                          //十位数
        num[2] = (i % 1000 - num[1] - num[0]) / 100;               //百位数
        num[3] = (i - num[2] * 100 - num[1] * 10 - num[0]) / 1000; //千位数
        if ((num[0] == num[3]) && (num[1] == num[2]))
        { //对每一个四位数进行判断，若符合，使计数器加1
            count++, oneline++;
            (0 == oneline % 6) ? (printf("\n%d  ", i)) : (printf("%d  ", i));
        }
    }
    printf("\nthere are %d numbers", count);
    return 0;
}