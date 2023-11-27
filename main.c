#include "ProjectIndex.h"

int AcademyScores[15][5];

int main() {
    Sort();
    AcademyList();
    int UserChoose;
    printf("-----------------------------------------------------\n"
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
            break;
        case 2:
            Mode2();
            break;
        case 3:
            Mode3();
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice, please choose again.\n");
            goto INPUT;
    }
    return 0;
}
