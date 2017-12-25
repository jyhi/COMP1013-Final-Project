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

void inquire_student_display (Node *the_node, int assignment_number) {
    puts("The information of the student you inquire is:");
    printf("%s\t%d", the_node->name, the_node->id);
    for (int k = 0; k < assignment_number; k++) {
        printf("%.2lf\t", the_node->assignments[k]);
    }
}

//inquire the student's information by input the index of that student in the list
void inquire_by_index () {
    int student_index, index = 0, assignment_number = 0;
    bool hw_status[5] = {false};
    Node *head, *pnode, *result;
    FILE *fpsm = NULL;
    read_from_marks(fpsm, &head, hw_status);

    for (int i = 0; i < 5; i++){
        if (hw_status[i]){
            assignment_number++;
        }
    }
    printf("Index\tName\tID\t");
    for (int j = 0; j < assignment_number; j++) {
        printf("Assignment%d", j + 1 );
    }

    pnode = head;

    while (pnode != NULL) {
        printf("%d\t%s\t%d", index, pnode->name, pnode->id);
        for (int k = 0; k < assignment_number; k++) {
            printf("%.2lf\t", pnode->assignments[k]);
        }
        index++;
        pnode = pnode->next;
    }

    puts("Please input the student's index number:");
    fflush(stdin);
    scanf("%d", &student_index);

    for (int l = 0; l <= index; l++) {
        result = head;
        head = head -> next;
    }
    inquire_student_display (result, assignment_number);
}

//inquire the student's information by input the id number
void inquire_by_student_id () {
    int student_id, assignment_number = 0;
    bool hw_status[5] = {false};

    puts("Please input the student's id number:");
    fflush(stdin);
    scanf("%d", &student_id);

    Node *head, *pnode;
    FILE *fpsm = NULL;
    read_from_marks(fpsm, &head, hw_status);

    for (int i = 0; i < 5; i++){
        if (hw_status[i]){
            assignment_number++;
        }
    }

    pnode  = head;

    while (pnode != NULL) {
        if (pnode->id == student_id) {
            inquire_student_display (pnode, assignment_number);
            return;
        } else {
            pnode = pnode->next;
        }
    }

    puts("The input id number is not exist in the student list.");
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
