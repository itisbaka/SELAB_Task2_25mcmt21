#include "student.h"
#include "validation.h"
#include "grade_calculator.h"
#include "constants.h"
#include <iostream>
#include <iomanip>
#include <fstream>

// Constructor
Student::Student() : totalMarks(0), percentage(0.0), grade(""), cgpa(0.0), passed(false) {
    for (int i = 0; i < SUBJECTS; i++) {
        marks[i] = 0;
    }
}

// Parameterized constructor
Student::Student(const std::string& id, const std::string& name, const int marksArray[SUBJECTS]) 
    : studentID(id), studentName(name), totalMarks(0), percentage(0.0), grade(""), cgpa(0.0), passed(false) {
    for (int i = 0; i < SUBJECTS; i++) {
        marks[i] = marksArray[i];
    }
}

// Getters
std::string Student::getStudentID() const {
    return studentID;
}

std::string Student::getName() const {
    return studentName;
}

int Student::getMark(int index) const {
    if (index >= 0 && index < SUBJECTS) {
        return marks[index];
    }
    return -1;
}

int Student::getTotalMarks() const {
    return totalMarks;
}

double Student::getPercentage() const {
    return percentage;
}

std::string Student::getGrade() const {
    return grade;
}

double Student::getCGPA() const {
    return cgpa;
}

bool Student::isPassed() const {
    return passed;
}

// Setters
void Student::setStudentID(const std::string& id) {
    studentID = id;
}

void Student::setName(const std::string& name) {
    studentName = name;
}

void Student::setMarks(const int marksArray[SUBJECTS]) {
    for (int i = 0; i < SUBJECTS; i++) {
        marks[i] = marksArray[i];
    }
}

void Student::setMark(int index, int mark) {
    if (index >= 0 && index < SUBJECTS) {
        marks[index] = mark;
    }
}

// Calculate results using GradeCalculator module
void Student::calculateResults() {
    // Calculate total marks
    totalMarks = GradeCalculator::calculateTotalMarks(marks, SUBJECTS);
    
    // Calculate percentage
    percentage = GradeCalculator::calculatePercentage(totalMarks, TOTAL_MAX_MARKS);
    
    // Check pass status
    passed = GradeCalculator::checkPassStatus(marks, SUBJECTS, MIN_PASSING_MARKS);
    
    // Assign grade
    grade = GradeCalculator::assignGrade(percentage);
    
    // Calculate CGPA
    cgpa = GradeCalculator::calculateCGPA(grade);
}

// Display student information to console
void Student::display() const {
    std::cout << std::left << std::setw(15) << studentID 
              << std::setw(25) << studentName;
    for (int i = 0; i < SUBJECTS; i++) {
        std::cout << std::setw(8) << marks[i];
    }
    std::cout << std::setw(10) << totalMarks 
              << std::setw(12) << std::fixed << std::setprecision(2) << percentage 
              << std::setw(8) << grade 
              << std::setw(8) << std::fixed << std::setprecision(2) << cgpa 
              << std::endl;
}

// Display student information to file
void Student::displayToFile(std::ofstream& file) const {
    file << std::left << std::setw(15) << studentID 
         << std::setw(25) << studentName;
    for (int i = 0; i < SUBJECTS; i++) {
        file << std::setw(8) << marks[i];
    }
    file << std::setw(10) << totalMarks 
         << std::setw(12) << std::fixed << std::setprecision(2) << percentage 
         << std::setw(8) << grade 
         << std::setw(8) << std::fixed << std::setprecision(2) << cgpa 
         << std::endl;
}

