#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

int main()
{
    // Section F, Print out to the screen course title, programming language, WGU student ID, student name
    cout << "C867-Scripting & Programming: Applications\n";
    cout << "Language: C++\n";
    cout << "Student ID: 007197656\n";
    cout << "Name: Joshua Vinson\n";
    cout << endl;

    const int numStudents = 5;
    Roster classRoster; // create with the default constructor

    // In file main.cpp add studentData[] from task scenario into the main() function
    const string studentData[] =
    { 
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Joshua,Vinson,jvins34@wgu.edu,34,14,21,30,SOFTWARE"
    };

    for (int i = 0; i < numStudents; i++)
    {
        classRoster.parse(studentData[i]);
    }
    
    cout << "Displaying all students:" << endl;
    classRoster.printAll();

    classRoster.printInvalidEmails();

    for (int i = 0; i < numStudents; i++)
    {
        classRoster.printAvgDays(classRoster.classRosterArray[i]->getID());
    }
    
    cout << endl;

    classRoster.printByDegreeProgram(SOFTWARE);

    classRoster.removeStudent("A3");

    classRoster.printAll();

    classRoster.removeStudent("A3");

    return 0;
}