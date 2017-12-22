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


extern void read_from_students(FILE *fp, Node **head){
    char linebuf[BUFSIZE];
    Node *present, *next;
    fgets(linebuf, BUFSIZE, fp);//Clear the first line;
    present = (Node *)malloc(sizeof(Node));
    fscanf(fp, "%s %d", present->name, &present->id);
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
}

extern void read_from_marks(FILE *fp, Node **head, bool status[]){
    char linebuf[BUFSIZE];
    Node *present, *next;
    fscanf(fp, "%*s%s", linebuf);
    while (true){
        fscanf(fp, "%s", linebuf);
        status[get_hw_index(linebuf) - 1] = true;
        if (fgetc(fp) == '\n')
            break;
    }
    present = (Node *)malloc(sizeof(Node));
    fscanf(fp, "%s %d", present->name, &present->id);
    *head = present;
    for (int i = 0; i < 5; i++){
        if (status[i]){
            fscanf(fp, "%lf", &present->assignments[i]);
        }
    }    
    while (true){
        next = (Node *)malloc(sizeof(Node));
        if (fscanf(fp, "%s %d", next->name, &next->id) == EOF)
            break;
        for (int i = 0; i < 5; i++){
            if (status[i]){
                fscanf(fp, "%lf", &next->assignments[i]);
            }
        }
        present->next = next;
        present = next;
    }
    free(next);
    present->next = NULL;
    fclose(fp);
}