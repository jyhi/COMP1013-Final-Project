#include <string.h>

/**
 * @file inquire.cpp
 * @version 0.5
 * @author Laurence
 *
 * This file contains functions related to the Inquire option.
 */

#include "node.hpp"

void inquire_by_index () {

}

void inquire_by_student_id () {

}

extern void inquire (void) {
    int inquire_menu_choice;

    puts("Menu:\n");
    puts("1. By index\n");
    puts("2. By student id\n");
    puts("3. Quit\n");

    scanf("%d", &inquire_menu_choice);

    switch (inquire_menu_choice) {
        case 1:
            inquire_by_index();
            break;
        case 2:
            inquire_by_student_id();
        case 3:
            return;
    }
}