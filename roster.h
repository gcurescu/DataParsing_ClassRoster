#pragma once
#include "student.h"
#include "degree.h"
#include <stdio.h>
#include <iostream>

class Roster
{
public:
	Roster(const string studentData[], int sizeofStudentData, int maxCapacity);
	~Roster();
	Student** getStudents();
	void parseID(string row);

	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int numDays1, int numDays2, int numDays3, DegreeProgram degreeProgram);
	void removeByID(string studentID);
	void printAll();
	void printByDegreeProgram(DegreeProgram degreeprogram);
	void printInvalidEmailAddresss();
	void printAverageNumDays(string studentID);

private:
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* student[numStudents] = { nullptr, nullptr, nullptr, nullptr, nullptr };
	int maxCapacity;
	int studentCount;
	Student* *classRosterArray;
};