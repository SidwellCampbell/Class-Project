#include <iostream>
#include <stdio.h>
#include <string>
#include "degree.h"
#include "student.h"
using namespace std;

    Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int courseOne,int courseTwo, int courseThree, DegreeProgram degreeprogram)
    : studentID(studentID), firstName(firstName), lastName(lastName), emailAddress(emailAddress), age(age), degreeProgram(degreeprogram)
    {
        daysInCourses[0] = courseOne;
        daysInCourses[1] = courseTwo;
        daysInCourses[2] = courseThree;
    }

Student::~Student(){
    cout << "STUDENT DELETED" <<endl;
}
   // GETTERS
    
    string Student::getStudentID(){
        
        return studentID;
    };
    
    string Student::getFirstName(){
        return firstName;
    };
    
    string Student::getLastName(){
        return lastName;
    };
    
    string Student::getEmail(){
        return emailAddress;
    };
    
    int Student::getAge(){
        return age;
    };
    
    int Student::getDaysInCourse(int arrayPosition){
        return daysInCourses[arrayPosition];
    };
    
    DegreeProgram Student::getDegree(){
        return degreeProgram;
    };
    
    //SETTERS
    
    void Student::setStudentID(string studentID){
        studentID = studentID;
        };
    
    void Student::setFirstName(string firstName){
        firstName = firstName;
    };
    
    void Student::setLastName(string lastName){
        lastName = lastName;
    };
    
    void Student::setEmail(string Email){
        emailAddress = Email;
    };
    
    void Student::setAge(int age){
        age = age;
    };
    
    void Student::setDaysInCourse(int arrayPosition, int numberOfDays){
        daysInCourses[arrayPosition] = numberOfDays;
    };
    
    void  Student::setDegree(DegreeProgram major){
        degreeProgram = major;
    };
    
    void Student::print(){
        
    //CASE STATEMENT TO CONVERT ENUM VALUE TO STRING
        string enumToString;
        switch (getDegree()) {
            case 0:
                enumToString = "SECURITY";
                break;
            case 1:
                enumToString = "NETWORK";
                break;
            case 2:
                enumToString = "SOFTWARE";
                break;
            default:
                break;
        }
        cout << getStudentID() << "\tFirst Name: "<<getFirstName() << "\tLast Name: "<< getLastName() <<"\tEmail: "<< getEmail() << "\tAge:"<< getAge() <<"\tDaysInCourses: {"<< daysInCourses[0] << "," << daysInCourses[1] << "," << daysInCourses[2] << "} \t Degree Program: "<< enumToString <<endl;
    };
    
       

