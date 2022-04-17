/*从一大堆连续数字中找特征数模板*/
#include <stdio.h>
#define from 100 //范围下限
#define to 999   //范围上限
#define condition i == num[0] * num[0] * num[0] + num[1] * num[1] * num[1] + num[2] * num[2] * num[2]
#define everyline_word 8
int main()
{
    int num[3];                  //用于存放3位数字的数组
    int i;                       //用于构建所有数的变量
    int count = 0;               //四位数的个数
    int oneline = -1;            //换行计数器
    for (i = from; i <= to; i++) //从1000开始构建所有四位数
    {
        num[0] = i % 10;                             //个位数
        num[1] = (i % 100 - num[0]) / 10;            //十位数
        num[2] = (i % 1000 - num[1] - num[0]) / 100; //百位数
        if (condition)
        { //对每一个3位数进行判断，若符合，使计数器加1
            count++, oneline++;
            (0 == oneline % everyline_word) ? (printf("\n%d\t", i)) : (printf("%d\t", i));
        }
    }
    printf("\nthere are %d numbers", count);
    return 0;
}