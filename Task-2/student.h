#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <fstream>
#include "constants.h"
using namespace std;

class Student {
private:
    string studentID;
    string studentName;
    int marks[SUBJECTS];
    int totalMarks;
    double percentage;
    string grade;
    double cgpa;
    bool passed;

public:
    // Constructors
    Student();
    Student(const string& id, const string& name, const int marksArray[SUBJECTS]);

    // Getters
    string getStudentID() const;
    string getName() const;
    int getMark(int index) const;
    int getTotalMarks() const;
    double getPercentage() const;
    string getGrade() const;
    double getCGPA() const;
    bool isPassed() const;

    // Setters
    void setStudentID(const string& id);
    void setName(const string& name);
    void setMarks(const int marksArray[SUBJECTS]);
    void setMark(int index, int mark);

    // Calculation method
    void calculateResults();

    // Display methods
    void display() const;
    void displayToFile(ofstream& file) const;
};

#endif 

