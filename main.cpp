#include "roster.h"
#include "degree.h"
#include "student.h"
#include <iostream>
#include <string>
using namespace std;


int main(int argc, const char * argv[]) {
    const string studentData[] =
    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Tevin,Campbell,tcam156@wgu.edu,31,19,14,17,SOFTWARE"};
    // insert code here...
    
    //COURSE DETAILS PRINTOUT
    cout << "Course Title: Scripting and Programming Applications - C867" << endl
    << "Programming language used: C++" <<endl
    << "Student ID: 001307311" << endl
    << "Name: Tevin Campbell" <<endl;
    
    cout << "-------------------" <<endl;
    cout<<endl;
    
    //CREATION OF ROSTER CLASS INSTANCE
    Roster classRoster;
    
    //ADD EACH STUDENT TO ROSTER
    for(string rowOfData : studentData) {
        classRoster.ParseData(rowOfData);
    };
    
    //PRINT STUDENTS, THEN PRINT INVALID EMAILS, THEN LOOP THROUGH ARRAY AND PRINT AVERAGE DAYS IN COURSES
    classRoster.printAll();
    cout << "-------------------" <<endl;
    cout<<endl;
    
    classRoster.printInvalidEmails();
    cout << "-------------------" <<endl;
    cout<<endl;
    
    for(Student* student: classRoster.classRosterArray) {
        string iD = student->getStudentID();
        classRoster.printAverageDaysInCourse(iD);
        
    }
    
    cout << "-------------------" <<endl;
    cout<<endl;
    
    classRoster.printByDegreeProgram(SOFTWARE);
    
    cout << "-------------------" <<endl;
    cout<<endl;

    classRoster.remove("A3");

    classRoster.printAll();
    
    cout << "-------------------" <<endl;
    cout<<endl;

    classRoster.remove("A3");
    
    classRoster.~Roster();
    
    return 0;
}
