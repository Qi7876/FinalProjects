/*
 * Created by Qiiwww on 11/21/23.
 * Statistic of the whole academy.
 */

#include "ProjectIndex.h"

int Mode2(void) {
    char FileName[15];
    int NumCount = 1, StudentsNum;
    float AverageScores;
    struct student *pStudents;
    fprintf(stdout, " Academy Scores List:\n"
                    "---------------------------------------------\n"
                    " Num | Class | Students Num | Average Scores \n");
    for (int i = 0; i < 15; ++i) {
        if (AcademyScores[i][0] == 0) {
            continue;
        }
        sprintf(FileName, "20230109%02d.txt", i + 1);
        StudentsNum = ReadStudentInfo(FileName, &pStudents);
        AverageScores = Count(pStudents, StudentsNum);
        fprintf(stdout, " %-3d |   %-3d |      %-3d     |      %-3.1f\n", NumCount, i + 1, AcademyScores[i][0], AverageScores);
        NumCount++;
        free(pStudents);
    }
    return 1;
}