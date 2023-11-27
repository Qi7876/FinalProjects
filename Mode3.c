/*
 * Created by Qiiwww on 11/21/23.
 * Broken line graph of single class on scores.
 */

#include "ProjectIndex.h"

int Mode3(void) {
    int UserChoose, ChooseList[15], Index = 0;

    for (int i = 0; i < 15; ++i) {
        if (AcademyScores[i][0] != 0) {
            printf("%d: Admin Class %d\n", Index + 1, i + 1);
            ChooseList[Index] = i;
            Index++;
        }
    }
    fprintf(stdout, "Please Choose a admin class to draw broken line graph: \n");
    scanf("%d", &UserChoose);
    fprintf(stdout, "You choose the Admin Class %d\n\n", ChooseList[UserChoose - 1] + 1);

    RenderLineChart(AcademyScores[ChooseList[UserChoose - 1]], 4);

    return 1;
}