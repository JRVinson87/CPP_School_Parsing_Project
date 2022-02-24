#include <iostream>
#include <string>
#include "student.h"

using namespace std;

// first match the paramaterless default constructor
Student::Student()
{
	this->studentID = "";
	this->fName = "";
	this->lName = "";
	this->email = "";
	this->age = 0;
	for (int i = 0; i < courseCompleteSize; i++) this->numDaysComplete[i] = 0;
	this->degreeProgram = DegreeProgram::SOFTWARE;
}

// full constructor
Student::Student(string studentID, string fName, string lName, string email, 
	int age, int numDaysComplete[], DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->fName = fName;
	this->lName = lName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < courseCompleteSize; i++) this->numDaysComplete[i] = numDaysComplete[i];
	this->degreeProgram = degreeProgram;
}

// destructor for memory, good practice
Student::~Student()
{
}

// getters implimentation 
string Student::getID()
{
	return this->studentID;
}
string Student::getfName()
{
	return this->fName;
}
string Student::getlName()
{
	return this->lName;
}
string Student::getEmail()
{
	return this->email;
}
int Student::getAge()
{
	return this->age;
}
int* Student::getDays() // pointer to int
{
	return this->numDaysComplete;
}
DegreeProgram Student::getDegree()
{
	return this->degreeProgram;
}

// setters implimentation 
void Student::setID(string ID)
{
	this->studentID = ID;
}
void Student::setfName(string fName)
{
	this->fName = fName;
}
void Student::setlName(string lName)
{
	this->lName = lName;
}
void Student::setEmail(string email)
{
	this->email = email;
}
void Student::setAge(int age)
{
	this->age = age;
}
void Student::setDays(int numDaysComplete[])
{
	for (int i = 0; i < courseCompleteSize; i++)
		this->numDaysComplete[i] = numDaysComplete[i];
}
void Student::setDegree(DegreeProgram degree)
{
	this->degreeProgram = degree;
}

// specific student print implimentation
void Student::print()
{
	cout << this->getID() << '\t';
	cout << this->getfName() << '\t' << '\t'; // double tab matches 'expected output' formatting
	cout << this->getlName() << '\t';
	cout << this->getAge() << '\t' << '\t'; // double tab matches 'expected output' formatting
	cout << "{" << this->getDays()[0] << ',';
	cout << this->getDays()[1] << ',';
	cout << this->getDays()[2] << "}" << '\t';
	cout << degreeProgramStrings[this->getDegree()] << endl;
}