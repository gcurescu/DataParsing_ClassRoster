#include "roster.h"
#include "student.h"
#include "degree.h"

using namespace std;

Student** Roster::getStudents()
{
	return Roster::student;
}

Roster::Roster(const string studentData[], int sizeofStudentData, int maxCapacity) {
	this->studentCount = sizeofStudentData;
	this->classRosterArray = new Student * [maxCapacity];
	this->maxCapacity = maxCapacity;
}

void Roster::parseID(string data)
{
	DegreeProgram degreeProgram = DegreeProgram::NONE;
	if (data.back() == 'Y') degreeProgram = DegreeProgram::SECURITY;
	else if (data.back() == 'K') degreeProgram = DegreeProgram::NETWORK;
	else if (data.back() == 'E') degreeProgram = DegreeProgram::SOFTWARE;

	string parsed[8];
	int rhs = 0;
	int lhs = 0;
	for (int i = 0; i < 8; i++)
	{
		rhs = data.find(",", lhs);
		parsed[i] = data.substr(lhs, rhs - lhs);
		lhs = rhs + 1;
	}

	add(
		parsed[0],//StudentID
		parsed[1],//First Name
		parsed[2],//Last Name
		parsed[3],//Email Address
		stod(parsed[4]),//Age
		stod(parsed[5]),//Num Days 1
		stod(parsed[6]),//Num Days 2
		stod(parsed[7]),//Num Days 3
		degreeProgram //Degree Program
	);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int numDays1, int numDays2, int numDays3, DegreeProgram degreeProgram)
{
	int numDaysArray[3] = { numDays1,numDays2,numDays3 };
	student[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, numDaysArray, degreeProgram);
}

void Roster::printAll()
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) Roster::student[i]->print();
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	//Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++)
		if (Roster::student[i]->getDegreeProgram() == degreeProgram) student[i]->print();
}

void Roster::printInvalidEmailAddresss()
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string emailAddress = Roster::getStudents()[i]->getEmailAddress();
		if (emailAddress.find(' ') != string::npos
			|| emailAddress.find('.') == string::npos
			|| emailAddress.find('@') == string::npos)
			cout << emailAddress << " is and invalid Email" << endl;
	}
}

void Roster::printAverageNumDays(string studentID)
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (student[i]->getStudentID() == studentID)
		{
			cout << "Student ID: " << studentID << ",";
			cout << "average days in sourse is: " << (student[i]->getNumDays()[0] +
				student[i]->getNumDays()[1] +
				student[i]->getNumDays()[2]) / 3 << endl;
		}
	}
}

void Roster::removeByID(string studentID)
{
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (student[i]->getStudentID() == studentID)
		{
			success = true;
			Student* temp = student[i];
			student[i] = student[numStudents - 1];
			student[numStudents - 1] = temp;
			Roster::lastIndex--;
		}
	}
	if (success)
	{
		//cout << "Student " << studentID << " removed." << endl;
		//printAll();
	}
	else cout << "The student with ID: " << studentID << " was  not found." << endl;
}

Roster::~Roster()
{
	for (int i = 0; i <= numStudents; i++)
	{
		cout << "Destructor called for " << student[i]->getStudentID() << endl;
		delete student[i];
		student[i] = nullptr;
	}
}