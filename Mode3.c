/*
 * Created by Qiiwww on 11/21/23.
 * Broken line graph of single class on scores.
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

    return 1;
}