#pragma once
#include "model.h"
void Addimfo(Students* students);
void Display(Students students);
node* Search(Students students, char* ID);
void DeleteAll(Students* students);
double AvgOfStudent(node* pnode);
void SubjectsMaxScore(Students students);