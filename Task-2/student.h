#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <fstream>
#include "constants.h"

/**
 * @class Student
 * @brief Represents a student with their academic information and results
 * 
 * This class encapsulates student data including ID, name, marks, and calculated
 * results (total, percentage, grade, CGPA, pass status).
 * 
 * Module Characteristics:
 * - Name: Student Module
 * - Cohesion: High (all methods operate on student data)
 * - Coupling: Low (only depends on constants.h)
 */
class Student {
private:
    std::string studentID;
    std::string studentName;
    int marks[SUBJECTS];
    int totalMarks;
    double percentage;
    std::string grade;
    double cgpa;
    bool passed;

public:
    // Constructors
    Student();
    Student(const std::string& id, const std::string& name, const int marksArray[SUBJECTS]);

    // Getters
    std::string getStudentID() const;
    std::string getName() const;
    int getMark(int index) const;
    int getTotalMarks() const;
    double getPercentage() const;
    std::string getGrade() const;
    double getCGPA() const;
    bool isPassed() const;

    // Setters
    void setStudentID(const std::string& id);
    void setName(const std::string& name);
    void setMarks(const int marksArray[SUBJECTS]);
    void setMark(int index, int mark);

    // Calculation method
    void calculateResults();

    // Display methods
    void display() const;
    void displayToFile(std::ofstream& file) const;
};

#endif // STUDENT_H

