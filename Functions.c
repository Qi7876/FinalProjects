/*
 * Created by Qiiwww on 11/21/23.
 * 储存自定义函数
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct student {
    char Name[10];
    char ID[15];
    int TrialScores;
    int MidScores;
    int TotalScores;
};

int StrToInt(const char *string) {
    int ResultInt = 0;
    for (int i = 0; '0'<= string[i] && string[i] <= '9'; ++i) {
        ResultInt = ResultInt * 10 + string[i] - '0';
    }
    return ResultInt;
}

int ReadStudentInfo(const char *filename, struct student **pStudents) {
    FILE *StudentsList;
    StudentsList = fopen(filename, "r");
    char Charact, Row[51];
    int StudentNum = 0;

    if (StudentsList == NULL) {
        fprintf(stderr, "文件打开错误,请检查格式是否正确。\n");
        return -1;
    }

    //获得行数，即学生个数
    while ((Charact = fgetc(StudentsList)) != EOF) {
        if (Charact == '\n') {
            StudentNum++;
        }
    }

    //分配内存
    *pStudents = (struct student *) malloc(StudentNum * sizeof(struct student));

    if (*pStudents == NULL) {
        fprintf(stderr, "内存分配失败。\n");
        return -1;
    }

    fseek(StudentsList, 0, SEEK_SET);

    //写入学生信息
    for (int i = 0; i < StudentNum; ++i) {
        fgets(Row, sizeof(Row), StudentsList);
        strcpy((*pStudents)[i].Name, strtok(Row, " "));
        strcpy((*pStudents)[i].ID, strtok(NULL, " "));
        (*pStudents)[i].TrialScores = StrToInt(strtok(NULL, " "));
        (*pStudents)[i].MidScores = StrToInt(strtok(NULL, " "));
        (*pStudents)[i].TrialScores = 0;
    }

    fclose(StudentsList);

    return StudentNum;
}

float Count(struct student pStu[], int num) {
    float Average = 0;
    for (int i = 0; i < num; ++i) {
        pStu[i].TotalScores = (pStu[i].TrialScores + pStu[i].MidScores) / 2;
        Average += (float)(pStu[i].TrialScores + pStu[i].MidScores);
    }
    Average /= (float)(2 * num);
    return Average;
}

int Class(char *ID) {
    int Class;
    char Temp[3];
    strncpy(Temp, ID + 8,2);
    Class = StrToInt(Temp);
    return Class;
}

void Sort() {

}