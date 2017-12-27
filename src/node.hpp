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
    double assignments[5 ];
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
3. The reference of function look like this: read_from_students(fp, &head);
4. The file pointer has closed in this function, you don't need to close it by yourself.
5. The function will return -1 if files have problem
*/
extern int read_from_students(FILE *fp, Node **head);


/*
1. Read information from marks.txt
2. Use "r" mode to open the file, otherwise the file would be wiped!!!
3. The reference of function look like this: read_from_marks(fp, &head, hw_status);
4. The file pointer has closed in this function, you don't need to close it by yourself.
5. The function will return -1 if files have problems
*/
extern int read_from_marks(FILE *fp, Node **head, bool status[]);

#endif /* end of include guard: _NODE_HPP */
