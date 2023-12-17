/**************************************************************************************************
 Name        : School Management System
 Author      : Mohamed Yahya Mohamed
 Description : This project is focused on student record services in school
 **************************************************************************************************/

#include <stdio.h>
#include "student.h"

int main() {
    printf("Welcome to the Student Management System!\n");
    int trials = 0;
    int choice;

    while (trials < 3) {
        if (MAIN_MENU(&choice) == 0) {
            break;
        } else if (choice == -1) {
            trials++;
            if (trials < 3) {
                printf("Invalid choice. You have %d trial(s) remaining.\n", 3 - trials);
            }
        } else {
            trials = 0; /* Reset trials if the user made a valid choice */
        }
    }

    if (trials == 3) {
        printf("You have exceeded the maximum number of trials. Exiting the program.\n");
    }

    // Free the allocated memory for the linked list before exiting.
    freeLinkedList();

    return 0;
}
