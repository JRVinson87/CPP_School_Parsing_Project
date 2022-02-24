#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

void Roster::parse(string studentdata)
{
	DegreeProgram dp;

	/* 
	use find function to hit first comma
	use substr function to extract string between index 0 and comma
	then go past the comma and continue to parse through all the data
	*/ 
	int rcom = studentdata.find(",");
	string sID = studentdata.substr(0, rcom);

	int lcom = rcom + 1;
	rcom = studentdata.find(",", lcom);
	string sFN = studentdata.substr(lcom, rcom - lcom);

	lcom = rcom + 1;
	rcom = studentdata.find(",", lcom);
	string sLN = studentdata.substr(lcom, rcom - lcom);

	lcom = rcom + 1;
	rcom = studentdata.find(",", lcom);
	string sEM = studentdata.substr(lcom, rcom - lcom);

	lcom = rcom + 1;
	rcom = studentdata.find(",", lcom);
	int sAG = stoi(studentdata.substr(lcom, rcom - lcom)); // stoi converts the string to int

	lcom = rcom + 1;
	rcom = studentdata.find(",", lcom);
	int sD1 = stoi(studentdata.substr(lcom, rcom - lcom));

	lcom = rcom + 1;
	rcom = studentdata.find(",", lcom);
	int sD2 = stoi(studentdata.substr(lcom, rcom - lcom));

	lcom = rcom + 1;
	rcom = studentdata.find(",", lcom);
	int sD3 = stoi(studentdata.substr(lcom, rcom - lcom));

	lcom = rcom + 1;
	string deg = studentdata.substr(lcom);
	if (deg == "SECURITY")
	{
		dp = SECURITY;
	}
	else if (deg == "NETWORK")
	{
		dp = NETWORK;
	}
	else
	{
		dp = SOFTWARE;
	}
	
	add(sID, sFN, sLN, sEM, sAG, sD1, sD2, sD3, dp);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress,
	int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
	// constructor wants an array but the days are separate, create an array
	int dayarray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	// book object index starts at -1 so that the increment can happen before creation
	// this makes a book!
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, dayarray, degreeprogram);
}

void Roster::removeStudent(string studentID)
{
	static int numCalled = 0;
	if (++numCalled > 1)
	{
		cout << "Removing " << studentID << " again" << endl;
		cout << endl;
	}
	else
	{
		cout << "Removing " << studentID << ":" << endl;
		cout << endl;
	}

	// start with the assumption there isn't a student to remove, then switch to true if one is found
	bool studentRemove = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getID() == studentID)
		{
			// a student is found, set to true so they're marked
			studentRemove = true;

			if (i < numStudents - 1)
			{
				// set a temporary pointer to swap the marked student
				Student* swap = classRosterArray[i]; // sets temp pointer to current index
				classRosterArray[i] = classRosterArray[numStudents - 1]; // sets current index to last index
				classRosterArray[numStudents - 1] = swap; // sets last index to temp pointer
			}
			Roster::lastIndex--; // using this to effectively remove the index by hiding it, destructor deals with it later
		}
	}
	if (!studentRemove)
	{
		cout << "The student with the ID: " << studentID << " was not found." << endl;
	}
}

void Roster::printAll()
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		classRosterArray[i]->Student::print(); // REVISION HERE, corrected the printAll to call print correctly
	}
	cout << endl;
}

void Roster::printAvgDays(string studentID)
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getID() == studentID)
		{
			cout << "Student ID: " << classRosterArray[i]->getID() << ", average days in course is: ";
			cout << (classRosterArray[i]->getDays()[0]
				+ classRosterArray[i]->getDays()[1] + classRosterArray[i]->getDays()[2]) / 3 << endl;
		}
	}
}

void Roster::printInvalidEmails()
{
	cout << "Displaying invalid emails:\n" << endl;

	bool invEmail = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string sEmail = (classRosterArray[i]->getEmail());
		int length = sEmail.length();
		// check each character for invalid entries
		for (int i = 0; i < length; i++)
		{
			int a = sEmail[i];
			if (isspace(a))
			{
				invEmail = true;
				cout << sEmail << " - is invalid." << endl;
			}
		}
		char at = sEmail.find("@");
		if (sEmail.find(".", at) == string::npos || at == string::npos)
		{
			invEmail = true;
			cout << sEmail << " - is invalid." << endl;
		}
	}
	if (!invEmail) cout << "No invalid email entries found." << endl;
	cout << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeprogram)
{
	cout << "Showing students in degree program: " << degreeProgramStrings[degreeprogram] << endl;
	cout << endl;

	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (Roster::classRosterArray[i]->getDegree() == degreeprogram)
		{
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}

Roster::~Roster()
{
	for (int i = 0; i < numStudents; i++)
	{
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
	cout << "DONE.";
}
