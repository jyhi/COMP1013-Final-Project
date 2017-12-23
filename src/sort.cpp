/**
 * @file sort.cpp
 * @version 0.1
 * @author
 *
 * This file contains functions related to the Sort option.
 */
#include "node.hpp"
#include <stdlib.h>
#include <string.h>
//Get total mark of each student
static void get_total(Node *head, bool status[]){
  Node *pnode = head;
  while (pnode != NULL){
    double sum = 0;
    for (int i = 0; i < 5; i++){
      if (status[i]){
        sum += pnode->assignments[i];
      }
    }
    pnode->total = sum;
    pnode = pnode->next;
  }
}

//Sort total mark using insert sort
static Node *insert_sort(Node *head){
  Node *current;//Record the smallest number currently
  Node *present;//Record the node current->next will insert
  Node *insert;//Record the node which will be insertede
  current = head;//Store the origin head of linked list
  while (current->next != NULL){
    if (current->total >= current->next->total){//If current->total is not the smallest 
      current = current->next;
      continue;
    }
    insert = current->next;
    current->next = insert->next;
    if (insert->total > head->total){//If current->next->total is the biggest number
      insert->next = head;
      head = insert;
      continue;
    }
    present = head;
    while (present->next != NULL){//Find the proper position to insert
      if (insert->total > present->next->total){
        insert->next = present->next;
        present->next = insert;
        break;
      }
      present = present->next;
    }
  }
  return head;
}

//Print result into file
static void file_print_result(Node *result){
  FILE *fpsw = fopen("sorted.txt", "w+");
  Node *pnode = result;
  fprintf(fpsw, "%-10s%-6s%s\n", "Name", "ID", "Total");
  while (pnode != NULL){
    fprintf(fpsw, "%-10s%-6d%.2f\n", pnode->name, pnode->id, pnode->total);
    pnode = pnode->next;
  }
  fclose(fpsw);
}

//Read from file and return the head of linked list
static Node *read_from_sorted(Node *new_node){
  FILE *fpsr = fopen("sorted.txt", "r");
  Node *pnode, *next;
  new_node = (Node *)malloc(sizeof(Node));
  char linebuf[BUFSIZE];
  if (fgets(linebuf, BUFSIZE, fpsr) == NULL)
    return NULL;
  if (fscanf(fpsr, "%s %d %lf", new_node->name, &new_node->id, &new_node->total) == EOF)
    return NULL;
  pnode = new_node;
  while(true){
    next = (Node *)malloc(sizeof(Node));
    if (fscanf(fpsr, "%s %d %lf", next->name, &next->id, &next->total) == EOF){
      free(next);
      pnode->next = NULL;
      break;
    }
    pnode->next = next;
    pnode = next;
  }
  return new_node;
}

extern void sort (void) {
  // Unimplemented
  bool hw_status[5] = {false};
  FILE *fpm = fopen("marks.txt", "r");
  Node *head, *pnode;
  read_from_marks(fpm, &head, hw_status);
  //Get total mark of each student
  get_total(head, hw_status);
  head = insert_sort(head);//Sort using insert sort
  //Print into file
  file_print_result(head);
  //Read from file
  Node *new_node = read_from_sorted(new_node);
  //Print the result out
  pnode = new_node;
  printf("%-10s%-6s%s\n", "Name", "ID", "Total");
  while (pnode != NULL){
    printf("%-10s%-6d%.2f\n", pnode->name, pnode->id, pnode->total);
    pnode = pnode->next;
  }
}
