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
static Node *insert_sort(Node *head, Node *result){
  result = (Node *)malloc(sizeof(Node));
  //Initialize result
  strcpy(result->name, head->name);
  result->id = head->id;
  result->total = head->total;
  result->next = NULL;
  //Initialize other nodes
  Node *present = head->next;//Node search in head
  Node *insert;//Insert value into result
  Node *pnode;//Record the current node in result and the next node in result
  while (present != NULL){
    pnode = result;
    //Intialize insert
    insert = (Node *)malloc(sizeof(Node));
    strcpy(insert->name, present->name);
    insert->id = present->id;
    insert->total = present->total;
    //When we need to insert it before result
    if (insert->total > result->total){//If the insert total is bigger than the head of result
      insert->next = result;
      result = insert;
      present = present->next;
      continue;
    }
    while (pnode != NULL){
      if (pnode->next == NULL){//If pnode is the last element
        pnode->next = insert;
        insert->next = NULL;
        break;
      }
      if (insert->total > pnode->next->total){//If pnode is not the last element
        insert->next = pnode->next;
        pnode->next = insert;
        break;
      }
      pnode = pnode->next;
    }
    present = present->next;
  }
  return result;
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
  fgets(linebuf, BUFSIZE, fpsr);
  fscanf(fpsr, "%s %d %lf", new_node->name, &new_node->id, &new_node->total);
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
  if(fpm == NULL){
    puts("File not exist.");
    exit(0);
  }
  Node *head, *pnode, *result;
  read_from_marks(fpm, &head, hw_status);
  //Get total mark of each student
  pnode = head;
  while (pnode != NULL){
    get_total(head, hw_status);
    pnode = pnode->next;
  }
  result = insert_sort(head, result);//Sort using insert sort
  //Print into file
  file_print_result(result);
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
