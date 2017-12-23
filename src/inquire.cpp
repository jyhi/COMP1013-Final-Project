#include <string.h>

/**
 * @file inquire.cpp
 * @version 1.0
 * @author Laurence
 *
 * This file contains functions related to the Inquire option.
 */

#include "node.hpp"

void inquire_by_index () {

}

void inquire_by_student_id () {

}

void inquire_student_display () {

}

extern void inquire (void) {
    int inquire_menu_choice;
    puts("===== Student Grading System =====\n");
    puts("Choose an option to start:");
    puts("Menu:");
    puts("1. By index");
    puts("2. By student id");
    puts("3. Quit\n");
    printf("Your Option: ");
    //display the menu

    fflush(stdin);
    scanf("%d", &inquire_menu_choice);

    switch (inquire_menu_choice) {
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