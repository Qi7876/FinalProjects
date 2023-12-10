#include "ProjectIndex.h"

int AcademyScores[15][5];

int main() {
    DIR *dir;
    struct dirent *entry;
    char currentDir[256];
    char *lastSlash;

    fprintf(stdout, "Start initializing.\n");
    strcpy(currentDir, __FILE__);
    lastSlash = strrchr(currentDir, '/');
    if (lastSlash != NULL) {
        *lastSlash = '\0';  // Cut off the string, only leave the part of directory.
    }

    // Open the current directory.
    dir = opendir(currentDir);

    if (dir == NULL) {
        fprintf(stderr, "Fail to open the current directory.\n");
        return -1;
    }

    while ((entry = readdir(dir)) != NULL) {
        // check whether the file is a txt or not.
        if (strstr(entry->d_name, "All") != NULL || strstr(entry->d_name, "20230109") != NULL) {
            remove(entry->d_name);
        }
    }

    Sort();
    AcademyList();
    int UserChoose;

    AGAIN:
    fprintf(stdout, "\n"
                    "-----------------------------------------------------\n"
           "|         Students' Scores Statistic System         |\n"
           "-----------------------------------------------------\n"
           "Please choose the work mode:\n"
           "(1) Statistic of single class\n"
           "(2) Statistic of the whole academy.\n"
           "(3) Broken line graph of single class on scores.\n"
           "(4) Exit\n");

    INPUT:
    scanf("%d", &UserChoose);

    switch (UserChoose) {
        case 1:
            Mode1();
            goto AGAIN;
        case 2:
            Mode2();
            goto AGAIN;
        case 3:
            Mode3();
            goto AGAIN;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice, please choose again.\n");
            goto INPUT;
    }
}
