/**
 * @file grade.cpp
 * @version 0.1
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

//Check the input of score
static char get_question_grade(int j){
	char c;
	char linebuf[BUFSIZE];
	while (true){
		printf("Question#%d. Please input mark: ", j + 1);
		fgets(linebuf, BUFSIZE, stdin);
		if (sscanf(linebuf, "%c",&c) != 1) {
			puts ("** Invalid input encounted! Please try again.");
			continue;
		}
		if ((c >= 'A' && c <= 'D') || c == 'F')
			break;
		else
			puts("Please input A, B, C, D or F");
	}
	return c;
}

//Process of grading for assignments
static void grading(Node **head,int index,int question){
	char c;//Character for storing grades of questions
	printf("\n===== Grade for Assignment%d start =====\n\n",index);
	Node *pnode;
	pnode = *head;
	while (pnode != NULL){
		double sum = 0;
		printf("===== Assignment%d %s =====\n\n", index, pnode->name);		
		for (int j= 0;j < question;j++){
			c = get_question_grade(j);
			sum += grade_in_num(c);
		}
		pnode->assignments[index-1] = sum / question;
		printf("\n===== Assignment%d %s Done =====\n\n", index, pnode->name);
		pnode = pnode->next;
	}
	printf("===== Grade for Assignment%d Done =====\n\n", index);
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

//Get and check the input value of homework index
static int get_hw_index(){
	int index;
	char c;
	while (true){
    	printf("Please input the index of this Assignment: ");
		if (scanf("%d", &index) != 1){
			puts("** Invalid input encounted! Please try again");
			while ((c = getchar()) != EOF && c!='\n');//Clear buffer
			continue;
		}
		if (index >= 1 && index <= 5)
			break;
		else
			puts("Please input integer between 1-5.");
	}
	return index;
}

//Get number of questions and check it
static int get_question_number(){
	int questions;
	char c;
	while (true){
    	printf("Please input the question number of this Assignment: ");
		if (scanf("%d", &questions) != 1){
			puts("** Invalid input encounted! Please try again");
			while ((c = getchar()) != EOF && c!='\n');//Clear buffer
			continue;
		}
		if (questions >= 1 && questions <= 10)
			break;
		else
			puts("Please input integer between 1-10.");
	}
	return questions;
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
	printf("===== Student Grading System =====\n\n");
    index = get_hw_index();
    hw_status[index-1] = true;
    questions = get_question_number();
	getchar();//Clear last '\n' from last input	
    grading(&head, index, questions);
    write_data(head, hw_status);
}
