
#ifndef roster_h
#define roster_h

#include "degree.h"
#include "student.h"
#include <iostream>
#include <string>

using  namespace std;

class Roster {
public:
    Student* classRosterArray[5];
    
    ~Roster();
    
  //ADD METHOD
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
    
    //PARSE DATA METHOD. ADD METHOD CALLED WITHIN
    void ParseData(string data);
    
    void remove(string studentID) ;
    
    void printAll();
    
    void printAverageDaysInCourse(string studentID);
    
    void printInvalidEmails();
    
    void printByDegreeProgram(DegreeProgram degreeProgram);

private:
    int lastindex = 0;
};

#endif
