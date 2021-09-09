#pragma once
#include <iostream>
#include <string> 
#include "degree.h"

using namespace std;

class Student 
{
public:
	const static int daysArraySize = 3;

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;

	int age;
	int numDays[daysArraySize];

	DegreeProgram degreeProgram;

public:
	Student();
	//Constructors
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numDays[], DegreeProgram degreeProgram);

	//Getters
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getNumDays();
	
	DegreeProgram getDegreeProgram();

	//Setters
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setNumDays(int numDays[]);
	
	void static printHeader();
	//void print();

	void setDegreeProgram(DegreeProgram degreeProgram);

	void print();

	//Destructor
	~Student();
};
