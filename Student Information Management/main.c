#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "model.h"
#include "stu_file.h"
#include "stu_service.h"
int main(void)
{
	//打印Menu
	printf("******************************\n");
	printf("Student Information Management\n");
	printf("******************************\n");
	printf("*************Menu*************\n");
	printf("1 Add student info\n");
	printf("2 Display student info\n");
	printf("3 Search student info\n");
	printf("4 Save student info to file\n");
	printf("5 Read student Info form file\n");
	printf("6 Select the avg score of a student\n");
	printf("7 Select the highest score for every subject\n");
	printf("8 Print Menu\n");
	printf("9 Delete all imfo from linked list\n");
	printf("0 Exit system\n");
	printf("******************************\n");
	int situation;
	const char* File_Name = "data.txt";				//定义文件名
	Students students = Read_From_File(File_Name);
	do{
		printf("Please enter your option(0~9):");
		scanf_s("%d", &situation);
		switch (situation)
		{
		case 0:break;
		case 1:Addimfo(&students); break;
		case 2:Display(students); break;
		case 3: {
			char ID[15];
			printf("Please enter the ID number of students:");
			scanf_s("%s", ID, 15);
			Search(students,ID);
			break;
		}
		case 4:Write_To_File(File_Name, students);break;
		case 5:Read_From_File(File_Name); break;
		case 6: {
			char ID[15];
			printf("Please enter the ID number of students:");
			scanf_s("%s", ID, 15);
			node* temp =  Search(students, ID);
			printf("******************************\n");
			printf("The Avg Score Of %s is %.2f\n", temp->student.Name, AvgOfStudent(temp));
			printf("******************************\n");
			break;
		}
		case 7: {
			//void SubjectsMaxScore(Students students)
			SubjectsMaxScore(students);
			break;
		}
		case 8: {
			printf("*************Menu*************\n");
			printf("1 Add student info\n");
			printf("2 Display student info\n");
			printf("3 Search student info\n");
			printf("4 Save student info to file\n");
			printf("5 Read student Info form file\n");
			printf("6 Select the avg score of a student\n");
			printf("7 Select the highest score for every subject\n");
			printf("8 Print Menu\n");
			printf("0 Exit system\n");
			printf("******************************\n");
		}
		case 9: {
			DeleteAll(&students);
		}
		default:
			printf("Input Error!Please Re-enter!\n");
		}
	} while (situation != 0);
	DeleteAll(&students);

	return 0;
}