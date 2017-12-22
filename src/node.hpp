/**
 * @file node.hpp
 * @version 0.1
 * @author
 *
 * This file contains prototypes of linked list.
 */

#ifndef _NODE_HPP
#define _NODE_HPP
#include <stdio.h>
#define BUFSIZE 512
typedef struct node {
    char name[20];
    int id;
    double assignments[5];
    double total;
    struct node *next;
} Node;

/*
Check if this homework exist in marks.txt
Initialize it in the format of: bool hw_status[5] = {false}; in function grade inquire and sort
*/
extern bool hw_status[];

/*
1. Read information from students.txt
2. Use "r" mode to open the file, otherwise the file would be wiped!!!
3. Use this function if and only if the file pointer is not NULL.
4. The reference of function look like this: read_from_students(fp, &head);
*/
extern void read_from_students(FILE *fp, Node **head);


/*
1. Read information from marks.txt
2. Use "r" mode to open the file, otherwise the file would be wiped!!!
3. Use this function if and only if the file pointer is not NULL.
4. The reference of function look like this: read_from_marks(fp, &head, hw_status);
*/
extern void read_from_marks(FILE *fp, Node **head, bool status[]);

#endif /* end of include guard: _NODE_HPP */