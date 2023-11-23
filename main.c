#include "ProjectIndex.h"

int main() {
    int UserChoose;
    printf("---------------------------------\n"
           "|         学生成绩整理系统         |\n"
           "---------------------------------\n"
           "请选择模式：\n"
           "（1）单教学班成绩统计\n"
           "（2）学院成绩统计\n"
           "（3）教学班成绩段人数分布折线图\n"
           "（4）退出\n");

    INPUT:
    scanf("%d", &UserChoose);

    switch (UserChoose) {
        case 1:
            Mode1();
            break;
        case 2:
            Mode2();
            break;
        case 3:
            Mode3();
            break;
        case 4:
            printf("程序已退出。\n");
            return 0;
        default:
            printf("非法的选项，请重新选择。\n");
            goto INPUT;
    }
    return 0;
}
