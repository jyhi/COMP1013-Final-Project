/**
 * @file node.cpp
 * @version 0.1
 * @author
 *
 * This file contains functions on operations about linked list.
 */
#include <stdlib.h>
#include "node.hpp"

//Get the index of Assignment exist in marks.txt
static int get_hw_index(char str[]){
    return (int) str[10] - 48;
}


extern int read_from_students(FILE *fp, Node **head){
    char linebuf[BUFSIZE];
    Node *present, *next;
    if(fp == NULL){
        puts("students.txt: File not exist.");
        return -1;
    }
    if (fgets(linebuf, BUFSIZE, fp) == NULL){
        puts("students.txt is empty.");
        return -1;
    }
    present = (Node *)malloc(sizeof(Node));
    if (fscanf(fp, "%s %d", present->name, &present->id) == EOF){
        puts("No data in students.txt");
        return -1;
    }
    *head = present;
    while (true){
        next = (Node *)malloc(sizeof(Node));
        if (fscanf(fp, "%s %d", next->name, &next->id) == EOF)
            break;
        present->next = next;
        present = next;
    }
    free(next);
    present->next = NULL;
    fclose(fp);
    return 0;
}

extern int read_from_marks(FILE *fp, Node **head, bool status[]){
    char linebuf[BUFSIZE];
    Node *present, *next;
    if(fp == NULL){
        puts("marks.txt: File not exist.");
        return -1;
    }
    if (fscanf(fp, "%*s%s", linebuf) == EOF){
        puts("marks.txt is empty");
        return -1;
    }
    while (true){
        if (fscanf(fp, "%s", linebuf) == EOF)
            break;
        status[get_hw_index(linebuf) - 1] = true;
        if (fgetc(fp) == '\n')
            break;
    }
    present = (Node *)malloc(sizeof(Node));
    if (fscanf(fp, "%s %d", present->name, &present->id) == EOF){
        puts("No data in students.txt");
        return -1;
    }
    *head = present;
    //Scan the head of linked list
    for (int i = 0; i < 5; i++){
        if (status[i]){
            if (fscanf(fp, "%lf", &present->assignments[i]) == EOF){
                 puts("Something wrong with marks.txt");
                 return -1;
            }
        }
    }    
    //Scan other nodes of linked
    while (true){
        next = (Node *)malloc(sizeof(Node));
        if (fscanf(fp, "%s %d", next->name, &next->id) == EOF)
            break;
        for (int i = 0; i < 5; i++){
            if (status[i]){
                if (fscanf(fp, "%lf", &next->assignments[i]) == EOF){
                    puts("Something wrong with marks.txt");
                    return -1;
                }
            }
        }
        present->next = next;
        present = next;
    }
    free(next);
    present->next = NULL;
    fclose(fp);
    return 0;
}
