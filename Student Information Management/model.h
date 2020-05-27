#pragma once
//Data shows the basic data of a student
typedef struct 
{
	char ID[15];
	char Name[40];
	char Gender;
	int Age;
	int CScore;
	int MathScore;
	int EngScore;
}Data;

//node is a basic element in the linked list
typedef struct _node
{
	Data student;
	struct _node* next;
}node;

//Students is the head of a linked list
typedef struct 
{
	node* head;
	int num;
}Students;