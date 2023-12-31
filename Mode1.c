/*
 * Created by Qiiwww on 11/21/23.
 * Statistic of single class
 */

#include "ProjectIndex.h"

int Mode1(void) {
    DIR *dir;
    struct dirent *entry;
    char fileNumber[256][256], currentDir[256];
    char *lastSlash, Temp[3];
    int fileCount = 0, userInput, StudentsNum;
    float AverageScores;
    struct student *pStudents;

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
        if (strstr(entry->d_name, "TeachingClass") != NULL) {
            printf("%d: %s\n", fileCount + 1, entry->d_name);
            strcpy(fileNumber[fileCount], entry->d_name);
            fileCount++;
        }
    }

    closedir(dir);

    printf("Please input the number of the file you want to process: \n");
    scanf("%d", &userInput);

    // Process the input of user.
    if (userInput >= 1 && userInput <= fileCount) {
        fprintf(stdout, "You choose the file: %s\n", fileNumber[userInput - 1]);
    } else {
        fprintf(stderr, "Invalid file.\n");
        return -1;
    }

    printf("Start processing.\n");
    StudentsNum = ReadStudentInfo(fileNumber[userInput - 1], &pStudents);

    AverageScores = Count(pStudents, StudentsNum);

    strncpy(Temp, fileNumber[userInput - 1] +13, 2);
    Temp[2] = '\0';

    fprintf(stdout, "-------------------------------------------------------------\n"
           "|                         Class：%-27d|\n"
           "-------------------------------------------------------------\n"
           " Num |  Name  |          ID          | Trial |  Mid  | Total \n", StrToInt(Temp));

    for (int i = 0; i < StudentsNum; ++i) {
        fprintf(stdout, " %-3d |  %-5s |     %s    |  %-3d  |  %-3d  |  %-3d\n", i + 1, pStudents[i].Name, pStudents[i].ID, pStudents[i].TrialScores, pStudents[i].MidScores, pStudents[i].TotalScores);
    }
    fprintf(stdout, "-------------------------------------------------------------\n"
                    " Average scores: %.1f\n", AverageScores);
    free(pStudents);
    return 1;
}