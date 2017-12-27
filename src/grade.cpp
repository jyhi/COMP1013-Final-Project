/**
 * @file grade.cpp
 * @version 1.1
 * @Millions of thanks to JACK
 *
 * This file contains functions related to the Grade option.
 */
#include <stdlib.h>
#include "node.hpp"
static int grade_in_num(char c){//Get the number of grade by letter grade
	switch (c){//Grading standard based on project assumptions
		case 'A':
			return 4;
				break;
		case 'B':
			return 3;
				break;
		case 'C':
			return 2;
				break;
		case 'D':
			return 1;
				break;
		default:
			return 0;
	}
}

//Process of grading for assignments
static void grading(Node **head,int index,int question){
	char c;//Character for storing grades of questions
	printf("Grade for Assignment%d start\n",index);
	Node *pnode;
	pnode = *head;
	while (pnode != NULL){
		double sum = 0;
		for (int j= 0;j < question;j++){
			printf("Now grading %s's Assignment%d, question%d.Please input mark: ",pnode->name,index,j + 1);
			scanf("%*c%c",&c);
			sum += grade_in_num(c);
		}
		pnode->assignments[index-1] = sum / question;
		printf("Grade of %s,Assignment%d done.\n", pnode->name ,index);
		pnode = pnode->next;
	}
	puts("Process of gradingProcess of grading finished.");
}

//Write header of table for sorting
static void write_table_header(bool hw_status[],FILE *fp){
	fprintf(fp, "%-10s%-6s","Name","ID");
	for (int i = 0;i < 5;i++ ){
		if(hw_status[i])
			fprintf(fp, "\tAssignment%d",i + 1);
	}
	fprintf(fp,"\n");
}

//Write content of table for sorting
static void write_table_content(Node *head, FILE *fp, bool hw_status[]){
	Node *pnode;
	pnode = head;	
	while (pnode != NULL){
	  fprintf(fp, "%-10s%-6d", pnode->name, pnode->id);
      for (int j = 0; j < 5; j++){
        if (hw_status[j])
          fprintf(fp, "\t%-10.2f", pnode->assignments[j]);
      }
      fprintf(fp, "\n");
      pnode = pnode->next;
  }
}

//Output marks.txt
static void write_data(Node *head, bool hw_status[]){
    FILE *fp3 = fopen("marks.txt", "w+");
    write_table_header(hw_status, fp3);
    write_table_content(head, fp3, hw_status);
    puts("Marks have saved into marks.txt.");
    fclose(fp3);
}

extern void grade(void){
    //Input necessary information
    Node *head;
    head = (Node *)malloc(sizeof(Node));
    bool hw_status[5] = {false};
    FILE *fp1 = fopen("students.txt", "r");
    FILE *fp2 = fopen("marks.txt", "r");
    if (read_from_marks(fp2, &head, hw_status) == -1){
      if (read_from_students(fp1, &head) == -1){
        puts("Something wrong with students.txt");
        exit(0);
      }
    }
    int index;//Question index of this assignment
    int questions;//Number of questions in this assignment
    //Confirm number of questions and index of this assignment
    printf("Please input the index of this Assignment: ");
    scanf("%d", &index);
    hw_status[index-1] = true;
    printf("Please input the question number of this Assignment: ");
    scanf("%d", &questions);
    grading(&head, index, questions);
    write_data(head, hw_status);
}
