// talkback.c -- 演示与用户交互
#include <stdio.h>
#include <string.h> //提供strlen()函数的原型
#define DNA 62.4    //人体密度（单位：磅/立方英尺）
int main()
{
    float weight, volume;
    char ' ';
    int size, letters, size2;
    char name[40]; // name是一个可容纳40个字符的数组
    printf("Hi! What's your first name?\n");
    printf("Hi! What's your first name?\n");
    scanf("%s", name);
    printf("%s,what's your weight in pounds?\n", name);
    scanf("%f", &weight);
    size = sizeof name;
    size2 = sizeof(_Bool);
    letters = strlen(name);
    volume = weight / DNA;
    printf("Well, %s, your volume is %2.2f cubic feet.\n", name, volume);
    printf("Also, your first name has %d letters,\n", letters);
    printf("and we have %d bytes to store it.\n", size);
    printf("and we have %d bytes to store it.\n", size2);
    return 0;
}