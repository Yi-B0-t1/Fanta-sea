#include <stdio.h>
int main()
{
    char ch;
    scanf("%c", &ch);                                            //测试在%号前加空格于不加的效果：不加空格则%c可以输入空格，而像现在这样就不能加空格
    printf("astring%cAAA", ch);                                  //这是%c的输出效果
    printf("changable number:%-*.*f", 12, 2, 1234.5678);         //可变字段宽度的应用办法和效果（用*修饰符实现）
    printf("Count Beppo ran %10.2f miles in 3 hours.\n", 10.22); //试验合适的字段宽度（10是不必要的，有多余的空格，不合适）
    printf("%c%c%c\n", 'H', 105, '\41');                         //%c对应参数的不同表达方式，单字符，ASCII码，\数字（表示特定符号）
    return 0;
}