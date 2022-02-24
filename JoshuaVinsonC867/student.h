#pragma once
#include <iostream>
#include <string>
#include "degree.h"

using namespace std;

// In files student.h and student.cpp create the Student class
class Student
{
	public:
		// Array needs to be a constant size and defined first
		const static int courseCompleteSize = 3;

	private:
		// Private since these should only be accessed in the class
		string studentID, fName, lName, email;
		int age;
		int numDaysComplete[courseCompleteSize];
		DegreeProgram degreeProgram;

	// second public for methods, cleaner
	public:
		// constructors - match class name
		Student(); //class constructor, blank for default values
		Student(string studentID, string fName, string lName, string email, 
			int age, int numDaysComplete[], DegreeProgram degreeProgram); //completed constructor
		~Student(); // destructor for memory

		// getters
		string getID();
		string getfName();
		string getlName();
		string getEmail();
		int getAge();
		int* getDays(); // pointer to int
		DegreeProgram getDegree();

		// setters - also called mutators
		void setID(string ID);
		void setfName(string fName);
		void setlName(string lName);
		void setEmail(string email);
		void setAge(int age);
		void setDays(int numDaysComplete[]);
		void setDegree(DegreeProgram degree);

		void print(); // can use this for specific student data
};