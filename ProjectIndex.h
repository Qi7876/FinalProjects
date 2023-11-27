/*
 * Created by Qiiwww on 11/21/23.
 */

#ifndef FINALPROJECTS_PROJECTINDEX_H
#define FINALPROJECTS_PROJECTINDEX_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <dirent.h>

struct student {
 char Name[10];
 char ID[15];
 int TrialScores;
 int MidScores;
 int TotalScores;
};

extern int AcademyScores[15][5];

int StrToInt(const char *string);
int ReadStudentInfo(const char *filename, struct student **pStudents);
float Count(struct student pStu[], int num);
int Class(char *ID);
int Mode1(void);
int Mode2(void);
int Mode3(void);
int Sort(void);
void AcademyList(void);



#endif //FINALPROJECTS_PROJECTINDEX_H
