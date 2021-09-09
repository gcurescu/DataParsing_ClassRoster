#include "roster.h"

int main()
{
	cout << "--------------------------------------------" << endl;
	cout << "C867: Scripting and Programming Applications" << endl;
	cout << "Language used: C++" << endl;
	cout << "ID: 000928431" << endl;
	cout << "Gentillo Curescu" << endl;
	cout << "--------------------------------------------" << endl;
	cout << endl;


	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Gentillo,Curescu,gcuresc@wgu.edu,30,15,30,20,SOFTWARE"
	};
	const int numStudents = 5;

	Roster classRoster = Roster(studentData, 5, 20);

	for (int i = 0; i < numStudents; i++) classRoster.parseID(studentData[i]);

	classRoster.printAll();

	cout << "\nDisplaying invalid emails: " << endl<<endl;
	classRoster.printInvalidEmailAddresss();


	cout << " " << endl;
	for(int i = 0; i < numStudents; i++) classRoster.printAverageNumDays(classRoster.getStudents()[i]->getStudentID());


	cout << "\nShowing Students in degree program: " << degreeProgramStrings[3] << endl << endl;
		classRoster.printByDegreeProgram((DegreeProgram)3);


	cout << "\nRemoving A3: " << endl;
	classRoster.removeByID("A3");

	classRoster.printAll();

	cout << "\nRemoving A3: " << endl;
	classRoster.removeByID("A3");

	system("pause");

	return 0;





}