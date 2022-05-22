#include "prepare.h"  //函数原型声明与数据结构原型
#include "funtions.h" //函数定义
int main(void)
{
    while (1) //七个主功能，7*3个子功能
    {
        switch (menu_select()) //主菜单
        {
        case 1:
            menu1();
            break;
        case 2:
            menu2();
            break;
        case 3:
            menu3();
            break;
            /*键入与修改数据*/
        case 4:
            menu4();
            break;
        case 5:
            menu5();
            /*根据输入查询信息*/
            break;
        case 6:
            menu6();
            //导出所有数据
            break;
        case 0: //退出程序
            puts("Goodbye!\n");
            return 0;
        }
        system("pause");
        fflush(stdin);
    }
}