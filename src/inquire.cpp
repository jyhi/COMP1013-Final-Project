#include "node.hpp"
#include <stdlib.h>
#include <string.h>

/**
 * @file inquire.cpp
 * @version 1.0
 * @author Laurence
 *
 * This file contains functions related to the Inquire option.
 */

void inquire_student_display () {

}

void inquire_read_student_marks () {
    char szTest[500] = {0};
    bool hw_status[5] = {false};
    Node *head, *pnode, *result;
    FILE *fpsm = NULL;
    read_from_marks(fpsm, &head, hw_status);
    while(!feof(fpsm))
    {
        memset(szTest, 0, sizeof(szTest));
        fgets(szTest, sizeof(szTest) - 1, fpsm); // 包含了换行符
        printf("%s", szTest);
    }
    printf("\n");
    memset(szTest, 0, sizeof(szTest));
    fgets(szTest, sizeof(szTest) - 1, fpsm);
    printf("%s", szTest);
    printf("\n");
}

void inquire_by_index () {
    inquire_read_student_marks ();

    inquire_student_display ();
}

void inquire_by_student_id () {
    inquire_read_student_marks ();

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
