#include "node.hpp"
#include <stdlib.h>
#include <string.h>

/**
 * @file inquire.cpp
 * @version 1.5
 * @author Laurence
 *
 * This file contains functions related to the Inquire option.
 */

typedef struct student {
    char name[20];
    int id;
    double assignments[5];
} Student;


void inquire_student_display () {

}

void inquire_by_index () {
    Student inquire_students_array[20];

    char szTest[100] = {0};
    int read_count = 0, assignment_count = 0;
    bool hw_status[5] = {false};
    Node *head, *pnode, *result;
    FILE *fpsm = NULL;
    read_from_marks(fpsm, &head, hw_status);
    while(!feof(fpsm))
    {
        memset(szTest, 0, sizeof(szTest));
        if (read_count == 0) {
            fgets(szTest, sizeof(szTest) - 1, fpsm);
            puts("%s", szTest);
            assignment_count = szTest[strlen(szTest) - 1];
        } else {
            fscanf(fpsm, "%s", inquire_students_array[read_count - 1].name);
            for (int i = 0; i < assignment_count; i++) {
                fscanf(fpsm, "%lf", &inquire_students_array[read_count - 1].assignments[i]);
            }
        }
        read_count++;
    }


    inquire_student_display ();
}

void inquire_by_student_id () {
    Student inquire_students_array[20];

    char szTest[500] = {0};
    int read_count = 0, assignment_count = 0;
    bool hw_status[5] = {false};
    Node *head, *pnode, *result;
    FILE *fpsm = NULL;
    read_from_marks(fpsm, &head, hw_status);
    while(!feof(fpsm))
    {
        memset(szTest, 0, sizeof(szTest));
        if (read_count == 0) {
            fgets(szTest, sizeof(szTest) - 1, fpsm);
            assignment_count = szTest[strlen(szTest) - 1];
        } else {
            fscanf(fpsm, "%s", inquire_students_array[read_count - 1].name);
            for (int i = 0; i < assignment_count; i++) {
                fscanf(fpsm, "%lf", &inquire_students_array[read_count - 1].assignments[i]);
            }
        }
        read_count++;
    }

    inquire_student_display ();
}

extern void inquire (void) {
    //Unimplemented
    int inquire_menu_option;
    puts("===== Student Grading System =====\n");
    puts("Choose an option to start:");
    puts("Menu:");
    puts("1. By index");
    puts("2. By student id");
    puts("3. Quit\n");
    printf("Your Option: ");
    //display the menu

    fflush(stdin);
    scanf("%d", &inquire_menu_option);

    switch (inquire_menu_option) {
        case 1:
            inquire_by_index();
            break;
        case 2:
            inquire_by_student_id();
            break;
        case 3:
        default:
            break;
    }
}