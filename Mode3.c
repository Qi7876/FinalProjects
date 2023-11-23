/*
 * Created by Qiiwww on 11/21/23.
 * 教学班成绩段人数分布折线图
 */

#include "ProjectIndex.h"

int Mode3(void) {
    DIR *dir;
    struct dirent *entry;
    char fileNumber[256][256], currentDir[256];
    char *lastSlash;
    int fileCount = 0, userInput, StudentsNum;
    struct student *pStudents;

    strcpy(currentDir, __FILE__);
    lastSlash = strrchr(currentDir, '/');
    if (lastSlash != NULL) {
        *lastSlash = '\0';  // 截断字符串，只保留目录部分
    }

    // 打开当前目录
    dir = opendir(currentDir);

    if (dir == NULL) {
        fprintf(stderr, "当前目录打开失败。\n");
        return -1;
    }

    // 遍历目录
    while ((entry = readdir(dir)) != NULL) {
        // 检查文件名是否以 ".txt" 结尾
        if (strstr(entry->d_name, ".txt") != NULL) {
            printf("%d: %s\n", fileCount + 1, entry->d_name);
            strcpy(fileNumber[fileCount], entry->d_name);
            fileCount++;
        }
    }

    // 关闭目录
    closedir(dir);

    // 用户输入数字

    printf("请输入你想处理的文件编号: ");
    scanf("%d", &userInput);

    // 处理用户输入
    if (userInput >= 1 && userInput <= fileCount) {
        printf("选择的文件: %s\n", fileNumber[userInput - 1]);
        // 在这里可以添加处理文件的代码
    } else {
        fprintf(stderr, "非法的文件选择。\n");
        return -1;
    }

    printf("开始处理文件。\n");

    return 1;
}