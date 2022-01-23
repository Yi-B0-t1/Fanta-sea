//typesize.c -- 打印类型大小 
#include<stdio.h>
int main(){
/* C99为类型大小提供%zd转换说明 */
    printf("Type int has a size of %zd bytes.\n",sizeof(int));
    printf("Type char has a size of %zd bytes.\n",sizeof(char));
    printf("Type long has a size of %zd bytes.\n",sizeof(long));
    printf("Type long long has a size of %zd bytes.\n",sizeof(long long));
    printf("Type　double　has　a　size　of　%zd　bytes.\n",sizeof(double));
    printf("Type long double has a size of %zd bytes.\n",sizeof(long double));
    printf("Type _Bool has a size of %zd bytes.\n",sizeof(_Bool));
    printf("Type long double _Complex has a size of %zd bytes.\n",sizeof(long double _Complex));
    printf("Type float has a size of %zd bytes.\n",sizeof(float));
    float pi=3.1415926536;
    double pie=3.1415926536;
    printf("pi=%f   pi=%lf",pi,pie);
    return 0;
}