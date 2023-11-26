/*
 * Created by Qiiwww on 11/21/23.
 * Statistic of single class
 */

#include "ProjectIndex.h"

int Mode1(void) {
    DIR *dir;
    struct dirent *entry;
    char fileNumber[256][256], currentDir[256];
    char *lastSlash;
    int fileCount = 0, userInput, StudentsNum, AverageScores;
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
        if (strstr(entry->d_name, ".txt") != NULL && strstr(entry->d_name, "CMake") == NULL) {
            printf("%d: %s\n", fileCount + 1, entry->d_name);
            strcpy(fileNumber[fileCount], entry->d_name);
            fileCount++;
        }
    }

    closedir(dir);

    printf("Please input the number of the file you want to process: ");
    scanf("%d", &userInput);

    // Process the input of user.
    if (userInput >= 1 && userInput <= fileCount) {
        printf("You choose the file: %s\n", fileNumber[userInput - 1]);
    } else {
        fprintf(stderr, "Invalid file.\n");
        return -1;
    }

    printf("Start processing.\n");
    StudentsNum = ReadStudentInfo(fileNumber[userInput - 1], &pStudents);

    AverageScores = Count(pStudents, StudentsNum);

    fprintf(stdout, "-------------------------------------------------------------\n"
           "|                          Class：%-26d|\n"
           "-------------------------------------------------------------\n"
           " Num |  Name  |          ID          | Trial |  Mid  | Total \n", Class(fileNumber[userInput - 1]));

    for (int i = 0; i < StudentsNum; ++i) {
        fprintf(stdout, " %-3d |  %-5s |     %s    |  %-3d  |  %-3d  |  %-3d  \n", i + 1, pStudents[i].Name, pStudents[i].ID, pStudents[i].TrialScores, pStudents[i].MidScores, pStudents[i].TotalScores);
    }
    fprintf(stdout, "-------------------------------------------------------------\n"
                    " Average scores: %d\n", AverageScores);
    free(pStudents);
    return 1;
}