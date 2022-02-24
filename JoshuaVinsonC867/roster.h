#pragma once
#include <iostream>
#include <string>
#include "student.h"

using namespace std;

class Roster
{
	public:
		int lastIndex = -1;
		const static int numStudents = 5;
		Student* classRosterArray[numStudents];

		// Parse each set of data identified in the “studentData Table.”
		void parse(string row); 
		
		// Add each student object to classRosterArray.
		void add(string studentID, string firstName, string lastName, string emailAddress, 
			int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
		
		void removeStudent(string studentID);
		void printAll();
		void printAvgDays(string studentID);
		void printInvalidEmails();
		void printByDegreeProgram(DegreeProgram degreeprogram);
		~Roster(); // destructor, good practice

};