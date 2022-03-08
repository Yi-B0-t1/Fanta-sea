/* t_and_f.c -- C中的真和假的值 */
/*#include <stdio.h>
int main(void)
{
    int true_val, false_val;
    true_val = (10 > 2);   // 关系为真的值
    false_val = (10 == 2); // 关系为假的值
    printf("true = %d; false = %d \n", true_val, false_val);
    return 0;
}*/
// truth.c -- 哪些值为真
#include <stdio.h>
int main(void)
{
    int n = +3;
    while (n) //（测试语句）非0即为真，while语句即执行其循环体内容
        printf("%2d　is　true\n", n--);
    printf("%2d　is　false\n", n);
    n = -3;
    while (n) //测试语句为0则while语句结束
        printf("%2d　is　true\n", n++);
    printf("%2d　is　false\n", n);
    return 0;
}