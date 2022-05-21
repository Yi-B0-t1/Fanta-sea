#include "prepare.h"  //函数原型声明与数据结构原型
#include "funtions.h" //函数定义
int main(void)
{
    while (1) //七个主功能，7*3个子功能
    {
        switch (menu_select()) //主菜单
        {
        case 1:
            system("cls"); /* 清屏 */
            // input stream loaded
            puts("NOW you are in: Initialize from 3 files\n");
            if (openfiles()) //注意，不能把函数原型直接拷贝过来用，把类型名字去掉
            {                // create lists
                init();
                create_grade_list();
                //一鼓作气吧这写完吧，抄也罢，省也罢，完成是第一目标
                sort_slist();      //按照学号升序排序。
                sort_clist();      //按照课程号升序排序。
                sort_grade_list(); //按照平均成绩降序排序
            }
            printf("\n%f\n", grade_list[1].average_grade);
            break;
        case 2:
            menu2();
            break;
        case 3:
            /*键入与修改数据*/
            break;
        case 4:
            /*根据输入删除对应数据*/
            break;
        case 5:
            /*根据输入查询信息*/
            break;
        case 6:
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