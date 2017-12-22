/**
 * @file sort.cpp
 * @version 0.1
 * @author
 *
 * This file contains functions related to the Sort option.
 */
#include "node.hpp"
#include <stdlib.h>
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
static Node *insert_sort(Node *pnode, Node *result){
  if (pnode->total > result->total){
    pnode->next = result;
    result = pnode;
    return result;
  }
  Node *present = result->next;
  while (present->next != NULL){
    if (pnode->total > present->next->total){
      pnode->next = present->next;
      present->next = pnode;
      return result;
    }
    pnode = pnode->next;
  }
  present->next = pnode;
  return result;
}

int main (void) {
  // Unimplemented
  bool hw_status[5] = {false};
  FILE *fp = fopen("marks.txt", "r");
  if(fp == NULL){
    puts("File not exist.");
    exit(0);
  }
  Node *head, *pnode, *result;
  read_from_marks(fp, &head, hw_status);
  //Get total mark of each student
  pnode = head;
  while (pnode != NULL){
    get_total(head, hw_status);
    pnode = pnode->next;
  }
  //Begin to sort
  result = head;  
  pnode = head->next;
  while (pnode != NULL){
    result = insert_sort(pnode, result);
    pnode = pnode->next;
  }
  //Print out the result
  pnode = result;
  while (pnode != NULL){
    printf("%s %g\n", pnode->name, pnode->total);
    pnode = pnode->next;
  }
}
