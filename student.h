
#ifndef STUDENT_H
#define STUDENT_H

struct Student {
    char name[50];
    char dob[15];
    char ID[15];
    char address[100];
    char phone[15];
    float cs_score;
};



/* Function prototypes (declarations) */
int MAIN_MENU(int* choice);
void NEW_STUDENT();
void DELETE_STUDENT();
void STUDENT_LIST();
void STUDENT_EDIT();
void RANK_STUDENT();
void STUDENT_SCORE();
void FIND_STUDENT_BY_FIRST_NAME();
int TOTAL_STUDENTS();

#endif
