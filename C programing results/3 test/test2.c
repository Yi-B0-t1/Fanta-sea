#include<stdio.h>
int main(){
    printf("three numbers:%o,%d,%d\n",77);
    int x=0x100;
    double C=100.00000001;
    char A='A';
    char B;
    printf("dec=%d;octal=%o;hex=%x\n",x,x,x);
    printf("%c   %c\n",A,B);
    printf("dec=%d;octal=%#o;\\hex=%#x\n",x,x,x);
    printf("double C=%",C+0.0000001);
    return 0;
}