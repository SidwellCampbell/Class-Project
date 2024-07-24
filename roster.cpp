
#include "degree.h"
#include "roster.h"
#include "student.h"
#include <iostream>



Roster::~Roster(){
    cout << "DESTRUCTOR CALLED" <<endl;
    for(Student* student: classRosterArray) {
        if(student->getStudentID() != "") {
            delete student;
        }
    }
}

//ADD METHOD
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram){
    
   classRosterArray[lastindex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);
    lastindex++;
};
//PARSE DATA METHOD. ADD METHOD CALLED WITHIN
void Roster::ParseData(string data){
    string lineOfTableData[9];
    size_t leftComma = 0;
    size_t rightComma = 0;
    for (int i = 0; i < 9; i++) {
        rightComma = data.find(",", leftComma);
        lineOfTableData[i] = data.substr(leftComma,rightComma - leftComma);
        leftComma = rightComma+1;
    }
//IF ELSE STATEMENT TO CONVERT DEGREEPROGRAM STRING TO ENUM BEFORE ADD IS CALLED
    DegreeProgram major;
    if (lineOfTableData[8] == "SECURITY") {
        major = SECURITY;
    } else if(lineOfTableData[8] == "NETWORK") {
        major = NETWORK;
    } else {
        major = SOFTWARE;
        
    }
    
    
    add(lineOfTableData[0], lineOfTableData[1], lineOfTableData[2], lineOfTableData[3], stoi(lineOfTableData[4]), stoi(lineOfTableData[5]), stoi(lineOfTableData[6]), stoi(lineOfTableData[7]), major);
    
};

void Roster::remove(string studentID) {
    bool removed = false;
    for (Student* student: classRosterArray)
        if (student->getStudentID() == studentID) {
            delete student;
            removed = true;
        }
    if (!removed) {
        cout << "The student with the ID: " << studentID << " was not found" << endl;
    }
};

void Roster::printAll(){
    for(Student* student: classRosterArray) {
        if (student->getStudentID() != "") {
            student->print();
        }
    }
};

void Roster::printAverageDaysInCourse(string studentID) {
    int sum;
    for (Student* student: classRosterArray){
        if (student->getStudentID() == studentID) {
            sum = student->getDaysInCourse(0) + student->getDaysInCourse(1) + student->getDaysInCourse(2);
            int avg = sum / 3;
            cout << "Student ID: " << studentID << ". Average days in course: "<< avg << endl;
        }
    }
};

void Roster::printInvalidEmails() {
    for (Student* student: classRosterArray){
        string email = student->getEmail();
        if (email.find(" ") != std::string::npos || email.find("@") == std::string::npos || email.find(".") == std::string::npos) {
            cout << "Invalid Email: " << email << endl;
        }
    }
    
};

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for(Student* student: classRosterArray) {
        if (student->getDegree() == degreeProgram) {
            student->print();
        }
    }
};
