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
  if (!head)
    return NULL;

  Node *current;//Record the smallest number currently
  Node *present;//Record the node that node insert will insert after
  Node *insert;//Record the node which will be insertede
  current = head;//Store the origin head of linked list
  while (current->next != NULL){
    if (current->total >= current->next->total){//If current->total is not the smallest
      current = current->next;
      continue;
    }
    insert = current->next;
    current->next = insert->next;
    if (insert->total > head->total){//If insert->total is the biggest number
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
  FILE *fpsw = fopen("sorted.txt", "w+");//Open sorted.txt to write results in
  if (!fpsw) {
    puts ("** Fatal error: cannot open sorted.txt for write. Exiting.");
    exit (2);
  }
  Node *pnode = result;//Record current node
  fprintf(fpsw, "%-10s%-6s%s\n", "Name", "ID", "Total");//Write the first line
  while (pnode != NULL){//Write data into sorted.txt
    fprintf(fpsw, "%-10s%-6d%.2f\n", pnode->name, pnode->id, pnode->total);
    pnode = pnode->next;
  }
  fclose(fpsw);
}

//Read from file and return the head of linked list
static Node *read_from_sorted(Node *new_node){
  if (!new_node)
    return NULL;
  FILE *fpsr = fopen("sorted.txt", "r");
  if (!fpsr) {
    puts ("** Fatal error: cannot open sorted.txt for read. Exiting.");
    exit (2);
  }
  Node *pnode, *next;//pnode record current node, next get data from file
  char linebuf[BUFSIZE];
  if (fgets(linebuf, BUFSIZE, fpsr) == NULL)//Ignore the first line
    return NULL;
  if (fscanf(fpsr, "%s %d %lf", new_node->name, &new_node->id, &new_node->total) == EOF)
    return NULL;
  pnode = new_node;
  while(true){//Scan data into a linked list
    next = (Node *)malloc(sizeof(Node));
    if (!next) {
      fprintf (stderr, "** Fatal error: memory allocation failed at %s:%d. Abort.\n", __FILE__, __LINE__);
      abort ();
    }
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
  bool hw_status[5] = {false};
  FILE *fpm = fopen("marks.txt", "r");
  if (!fpm) {
    puts ("** Fatal error: cannot open marks.txt for read. Exiting.");
    return;
  }
  Node *head, *pnode;
  read_from_marks(fpm, &head, hw_status);
  //Get total mark of each student
  get_total(head, hw_status);
  //Sort using insert sort
  head = insert_sort(head);
  if (!head) {
    puts ("** Fatal error: insert_sort failed. Abort.");
    abort ();
  }
  //Print into file
  file_print_result(head);
  //Read from file
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node = read_from_sorted(new_node);
  //Print the result out
  pnode = new_node;
  printf("%-10s%-6s%s\n", "Name", "ID", "Total");
  while (pnode != NULL){
    printf("%-10s%-6d%.2f\n", pnode->name, pnode->id, pnode->total);
    pnode = pnode->next;
  }
}
