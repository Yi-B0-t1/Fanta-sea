/* do_while.c -- 出口条件循环 */
#include <stdio.h>
int main(void)
/*{
    const int secret_code = 13;
    int code_entered;
    do
    {
        printf("To enter the triskaidekaphobia therapyclub,\n");
        printf("please enter the secret codenumber:");
        scanf("%d", &code_entered);
    } while (code_entered != secret_code);
    printf("Congratulations!　You　are　cured!\n");
    return 0;
}*/
{
    const int secret_code = 13;
    int code_entered;
    printf("To enter the triskaidekaphobia therapyclub,\n");
    printf("please enter the secret codenumber:");
    for (code_entered = 0; code_entered != secret_code; scanf("%d", &code_entered))
        printf("here is scanf get:__%d__\nenter your new number:", code_entered);
    printf("Congratulations!　You　are　cured!\n");
    return 0;
}