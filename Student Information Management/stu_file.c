#include "model.h"
#include "stu_file.h"
#include <stdio.h>
Students Read_From_File(char* filename)
{
	printf("-------------------------------\n");
	printf("**Read student Info form file**\n");
	printf("_____________________________________________________________________________________________\n");
	FILE* fp;
	fopen_s(&fp, filename, "r");
	if (fp == NULL)  //检测是否成功打开
		printf("Read Open failed\n");
	Students students;
	students.head = NULL; students.num = File_len("data.txt");
	int i, j;
	for (i = 0; i < students.num; i++) {
		node* newnode = (node*)malloc(sizeof(node));
		if (fscanf_s(fp, "%s", newnode->student.ID, 10) == EOF) {
			students.head = NULL;
			students.num = 0;
			fclose(fp);
			printf("_____________________________________________________________________________________________\n");
			return students;
		}
		fscanf_s(fp, "%s", newnode->student.Name, 30);
		char a = fgetc(fp);
		fscanf_s(fp, "%c", &newnode->student.Gender);
		fscanf_s(fp, "%d", &newnode->student.Age);
		fscanf_s(fp, "%d", &newnode->student.CScore);
		fscanf_s(fp, "%d", &newnode->student.MathScore);
		fscanf_s(fp, "%d", &newnode->student.EngScore);
		if (i == 0) {
			printf("Student ID\tStudent Name\tGender\tAge\tC Score\t\tMath Score\tEnglish Score\n");
		}
		printf("%s\t\t%s\t\t%c\t%d\t%d\t\t%d\t\t%d\n", newnode->student.ID, newnode->student.Name,
			newnode->student.Gender, newnode->student.Age, newnode->student.CScore,
			newnode->student.MathScore, newnode->student.EngScore);
		newnode->next = students.head;
		students.head = newnode;
	}
	fclose(fp);
	printf("_____________________________________________________________________________________________\n");
	return students;
}
int File_len(char* filename)
{
	FILE* fp;
	fopen_s(&fp, filename, "r");
	int flag = 0, file_row = 0, count = 0;
	if (fp == NULL)  //检测是否成功打开
		printf("Open failed\n");
	while (!feof(fp))
	{
		flag = fgetc(fp);
		if (flag == '\n')
			count++;
	}
	file_row = count + 1; //加上最后一行
	fclose(fp);
	return file_row;
}
void Write_To_File(char* filename,Students students)
{
	printf("-------------------------------\n");
	printf("**Write student Info to file**\n");
	printf("-------------------------------\n");
	FILE* fp;
	fopen_s(&fp, filename, "w");
	if (fp == NULL)  //检测是否成功打开
		printf("Write Open failed\n");
	node* temp = students.head;
	while (temp) {
		fprintf(fp, "%s\t", temp->student.ID);
		fprintf(fp, "%s\t", temp->student.Name);
		fprintf(fp, "%c\t", temp->student.Gender);
		fprintf(fp, "%d\t", temp->student.Age);
		fprintf(fp, "%d\t", temp->student.CScore);
		fprintf(fp, "%d\t", temp->student.MathScore);
		fprintf(fp, "%d", temp->student.EngScore);
		if (temp->next != NULL) {
			fprintf(fp, "\n");
		}
		temp = temp->next;
	}
	fclose(fp);
	printf("-------------------------------\n");
	printf("Successfully Write!\n");
	printf("-------------------------------\n");
}