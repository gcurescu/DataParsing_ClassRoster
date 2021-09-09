#include <iostream>
#include <iomanip>
#include <string>
#include "student.h"
#include "degree.h" 

using namespace std;

//Default Constructor
Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = -1;
	for (int i = 0; i < daysArraySize; i++)
	{
		this->numDays[i] = 0;
	}
	this->degreeProgram = DegreeProgram::NONE;
}

//Constructor
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numDays[], DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysArraySize; i++) {
		this->numDays[i] = numDays[i];
	}
	this->degreeProgram = degreeProgram;
}

//Destructor
Student::~Student() {}

//Getters(Assessors) and Setters(Mutators)

string Student::getStudentID()
{
	return studentID;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getLastName()
{
	return lastName;
}

string Student::getEmailAddress()
{
	return emailAddress;
}

int Student::getAge()
{
	return age;
}

int* Student::getNumDays()
{
	return numDays;
}

DegreeProgram Student::getDegreeProgram()
{
	return degreeProgram;
}

void Student::setStudentID(string studentID)
{
	this->studentID = studentID;
}

void Student::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
	this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress)
{
	this->emailAddress = emailAddress;
}

void Student::setAge(int age)
{
	this->age = age;
}

void Student::setNumDays(int numDays[])
	
{
	for (int i = 0; i < daysArraySize; i++)
	{
		this->numDays[i] = numDays[i];
	}
}

void Student::setDegreeProgram(DegreeProgram degreeProgram)
{
	this->degreeProgram = degreeProgram;
}

void Student::printHeader()
{
	cout << "Displaying all students: "<< endl;
}
void Student::print()
{
	cout << studentID << "\t";
	cout << firstName << "\t\t";
	cout << lastName << "\t";
	cout << age << "\t\t";
	cout << "{" << numDays[0] << ", ";
	cout << numDays[1] << ", ";
	cout << numDays[2] << "} "<<"\t\t";
	cout << "";

	switch (degreeProgram) {
	case DegreeProgram::SECURITY:
		cout << "SECURITY";
		break;
	case DegreeProgram::NETWORK:
		cout << "NETWORK";
		break;
	case DegreeProgram::SOFTWARE:
		cout << "SOFTWARE";
		break;
	case DegreeProgram::NONE:
		cout << "NONE";
		break;
	}
	cout << endl;
	return;
}