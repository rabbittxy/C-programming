#include "model.h"
#include <stdio.h>
void Addimfo(Students* students)
{
	node* newnode = (node*)malloc(sizeof(node));
	printf("Student ID:");
	scanf_s("%s", newnode->student.ID, 10);
	printf("Student Name:");
	scanf_s("%s", newnode->student.Name, 30);
	getchar();
	printf("Gender:");
	scanf_s("%c", &newnode->student.Gender);
	printf("Age:");
	scanf_s("%d", &newnode->student.Age);
	printf("C Score:");
	scanf_s("%d", &newnode->student.CScore);
	printf("Math Score:");
	scanf_s("%d", &newnode->student.MathScore);
	printf("English Score:");
	scanf_s("%d", &newnode->student.EngScore);
	newnode->next = students->head;
	students->head = newnode;
	students->num++;
	printf("------------------------------\n");
	printf("Add Information Successfully!\n");
	printf("------------------------------\n");
}
void Display(Students students)
{
	printf("_____________________________________________________________________________________________\n");
	printf("Student ID\tStudent Name\tGender\tAge\tC Score\t\tMath Score\tEnglish Score\n");
	node* temp = students.head;
	while (temp) {
		printf("%s\t\t%s\t\t%c\t%d\t%d\t\t%d\t\t%d\n", temp->student.ID, temp->student.Name,
			temp->student.Gender, temp->student.Age, temp->student.CScore,
			temp->student.MathScore, temp->student.EngScore);
		temp = temp->next;
	}
	printf("_____________________________________________________________________________________________\n");
}
node* Search(Students students, char* ID)
{
	node* temp = students.head;
	while (temp) {
		if (strcmp(ID, temp->student.ID) == 0) {
			printf("------------------------------\n");
			printf("Found Successfully!\n");
			printf("The Name Of The Student is %s\n", temp->student.Name);
			printf("------------------------------\n");
			return temp;
		}
		temp = temp->next;
	}
	printf("------------------------------\n");
	printf("Not Found!\n");
	printf("------------------------------\n");
	return NULL;
}
void DeleteAll(Students* students)
{
	node* temp = students->head;
	while (temp) {
		node* next = temp->next;
		free(temp);
		temp = next;
	}
	students->head = NULL;
	students->num = 0;
	printf("------------------------------\n");
	printf("All Information Has Being Deleted!\n");
	printf("------------------------------\n");
}
double AvgOfStudent(node* pnode)
{
	return (pnode->student.CScore + pnode->student.MathScore + pnode->student.EngScore) / (double)3;
}
void SubjectsMaxScore(Students students)
{
	printf("------------------------------\n");
	node* temp = students.head;
	int max = temp->student.CScore;
	while (temp) {
		if (temp->student.CScore > max) {
			max = temp->student.CScore;
		}
		temp = temp->next;
	}
	printf("Max Score For C programming language is %d\n", max);
	temp = students.head;
	max = temp->student.MathScore;
	while (temp) {
		if (temp->student.MathScore > max) {
			max = temp->student.MathScore;
		}
		temp = temp->next;
	}
	printf("Max Score For Math is %d\n", max);
	temp = students.head;
	max = temp->student.EngScore;
	while (temp) {
		if (temp->student.EngScore > max) {
			max = temp->student.EngScore;
		}
		temp = temp->next;
	}
	printf("Max Score For English is %d\n", max);
	printf("------------------------------\n");
}