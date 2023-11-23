/*
 * Created by Qiiwww on 11/21/23.
 */

#ifndef FINALPROJECTS_PROJECTINDEX_H
#define FINALPROJECTS_PROJECTINDEX_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <dirent.h>

struct student{};
int StrToInt(const char *string);
int ReadStudentInfo(const char *filename, struct student **pStudents);
float Count(struct student pStu[], int num);
int Class(char *ID);
int Mode1(void);
int Mode2(void);
int Mode3(void);


#endif //FINALPROJECTS_PROJECTINDEX_H
