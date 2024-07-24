#ifndef student_h
#define student_h
#include <iostream>
#include <string>

using namespace std;
class Student {
public:
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int courseOne,int courseTwo, int courseThree, DegreeProgram degreeprogram);
    Student();
    ~Student();
   // GETTERS
    
    string getStudentID();
    
    string getFirstName();
    
    string getLastName();
    
    string getEmail();
    
    int getAge();
    
    int getDaysInCourse(int arrayPosition);
    
    DegreeProgram getDegree();
    
    //SETTERS
    
    void setStudentID(string studentID);
    
    void setFirstName(string firstName);
    
    void setLastName(string lastName);
    
    void setEmail(string Email);
    
    void setAge(int age);
    
    void setDaysInCourse(int arrayPosition, int numberOfDays);
    
    void  setDegree(DegreeProgram major);
    
    //PRINT METHOD
    
    void print();
    
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysInCourses[3];
    DegreeProgram degreeProgram;
};

#endif
