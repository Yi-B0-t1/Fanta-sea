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
            if (openfiles(file_stu, file_course, file_select)) //注意，不能把函数原型直接拷贝过来用，把类型名字去掉！
            {                                                  // create lists
                init(stu_list, stu_total, course_list, course_total, select_list, select_total);
                create_grade_list(stu_list, stu_total, course_list, course_total, select_list, select_total, grade_list);
                sort_slist(stu_list, stu_total);        //按照学号升序排序。
                sort_clist(course_list, course_total);  //按照课程号升序排序。
                sort_grade_list(grade_list, stu_total); //按照平均成绩降序排序
            }
            break;
        case 2:
            system("cls"); /* 清屏 */
            /*显示所有数据*/
            //复制初始化即可
            system("pause");
            break;
        case 3:
            /*键入与修改数据*/
            system("pause");
            break;
        case 4:
            /*根据输入删除对应数据*/
            system("pause");
            break;
        case 5:
            /*根据输入查询信息*/
            system("pause");
            break;
        case 6:
            //导出所有数据
            system("pause");
            break;
        case 0: //退出程序
            puts("Goodbye!\n");
            system("pause");
            exit(0);
        }
        clearline();
    }
    return 0;
}