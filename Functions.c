/*
 * Created by Qiiwww on 11/21/23.
 * The functions.
 */

#include "ProjectIndex.h"

int CompareByID(const void *a, const void *b) {
    return strcmp(((struct student*)a)->ID, ((struct student*)b)->ID);
}

int StrToInt(const char *string) {
    int ResultInt = 0;
    for (int i = 0; '0'<= string[i] && string[i] <= '9'; ++i) {
        ResultInt = ResultInt * 10 + string[i] - '0';
    }
    return ResultInt;
}

int ReadStudentInfo(const char *filename, struct student **pStudents) {
    FILE *StudentsList = fopen(filename, "r");
    char Charact, Row[51];
    int StudentNum = 0;

    if (StudentsList == NULL) {
        fprintf(stderr, "Fail to open the file.\n");
        return -1;
    }

    // Get the num of students.
    while ((Charact = fgetc(StudentsList)) != EOF) {
        if (Charact == '\n') {
            StudentNum++;
        }
    }

    // Alloc the memory.
    *pStudents = (struct student *) malloc(StudentNum * sizeof(struct student));

    if (*pStudents == NULL) {
        fprintf(stderr, "Fail to allot the memory.\n");
        return -1;
    }

    fseek(StudentsList, 0, SEEK_SET);

    // Write the information into memory.
    for (int i = 0; i < StudentNum; ++i) {
        fgets(Row, sizeof(Row), StudentsList);
        strcpy((*pStudents)[i].Name, strtok(Row, " "));
        strcpy((*pStudents)[i].ID, strtok(NULL, " "));
        (*pStudents)[i].TrialScores = StrToInt(strtok(NULL, " "));
        (*pStudents)[i].MidScores = StrToInt(strtok(NULL, " "));
        (*pStudents)[i].TotalScores = 0;
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

int Sort(void) {
    DIR *dir;
    struct dirent *entry;
    char fileNumber[256][256], currentDir[256];
    char *lastSlash, Temp[20];
    int fileCount = 0, StudentsNum;
    struct student *pStudents;
    FILE *TempAll, *AdminClassFiles, *All;

    fprintf(stdout, "Start sorting.\n");

    strcpy(currentDir, __FILE__);
    lastSlash = strrchr(currentDir, '/');
    if (lastSlash != NULL) {
        *lastSlash = '\0';  // Cut off the string, only leave the part of directory.
    }

    // Open the current directory.
    dir = opendir(currentDir);

    if (dir == NULL) {
        fprintf(stderr, "Fail to open the curent directort.\n");
        return -1;
    }

    // Directory travelsal
    while ((entry = readdir(dir)) != NULL) {
        // check whether the file is a txt or not.
        if (strstr(entry->d_name, ".txt") != NULL && strstr(entry->d_name, "CMake") == NULL) {
            printf("%d: %s\n", fileCount + 1, entry->d_name);
            strcpy(fileNumber[fileCount], entry->d_name);
            fileCount++;
        }
    }

    closedir(dir);
    printf("Start processing.\n");
    TempAll = fopen("TempAll.txt", "w");
    for (int i = 0; i < fileCount; ++i) {
        StudentsNum = ReadStudentInfo(fileNumber[i], &pStudents);
        Count(pStudents, StudentsNum);
        for (int j = 0; j < StudentsNum; ++j) {
            fprintf(TempAll, "%s %s %d %d %d\n", pStudents[j].Name, pStudents[j].ID, pStudents[j].TrialScores, pStudents[j].MidScores, pStudents[j].TotalScores);
        }
        free(pStudents);
    }
    fclose(TempAll);

    StudentsNum = ReadStudentInfo("TempAll.txt", &pStudents);
    Count(pStudents, StudentsNum);
    All = fopen("All.txt", "w");
    qsort(pStudents, StudentsNum, sizeof (struct student), CompareByID);
    for (int j = 0; j < StudentsNum; ++j) {
        fprintf(All, "%s %s %d %d %d\n", pStudents[j].Name, pStudents[j].ID, pStudents[j].TrialScores, pStudents[j].MidScores, pStudents[j].TotalScores);
        strncpy(Temp, pStudents[j].ID, 10);
        Temp[10] = '\0';
        strcpy(Temp + 10, ".txt\0");
        AdminClassFiles = fopen(Temp, "a");
        fprintf(AdminClassFiles, "%s %s %d %d %d\n", pStudents[j].Name, pStudents[j].ID, pStudents[j].TrialScores, pStudents[j].MidScores, pStudents[j].TotalScores);
        fclose(AdminClassFiles);
        }
    free(pStudents);
    fclose(TempAll);
    fclose(All);
    remove("TempAll.txt");
    return 1;
}

void AcademyList(void) {
    struct student *pStudents;
    int StudentsNum, ClassIndex, Total;
    StudentsNum = ReadStudentInfo("All.txt", &pStudents);
    Count(pStudents, StudentsNum);
    for (int i = 0; i < StudentsNum; ++i) {
        ClassIndex = Class(pStudents[i].ID);
        AcademyScores[ClassIndex - 1][0]++;
        Total = pStudents[i].TotalScores;
        if (Total < 60) {
            AcademyScores[ClassIndex - 1][1]++;
        }
        else if (Total < 75) {
            AcademyScores[ClassIndex - 1][2]++;
        }
        else if (Total < 85) {
            AcademyScores[ClassIndex - 1][3]++;
        } else {
            AcademyScores[ClassIndex - 1][4]++;
        }
    }
    free(pStudents);
}