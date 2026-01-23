#include "student_result_system.h"
#include "file_handler.h"
#include "statistics.h"
#include "grade_calculator.h"
#include "constants.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
StudentResultSystem::StudentResultSystem() {
}

bool StudentResultSystem::loadFromFile(const string& filename) {
    students.clear();
    studentIDs.clear();
    int count = FileHandler::readStudentDataFromFile(filename, students, studentIDs);
    return count > 0;
}

bool StudentResultSystem::saveToFile(const string& filename) const {
    if (!FileHandler::writeResultsToFile(filename, students)) {
        return false;
    }

    // Append statistics to file
    ofstream file(filename, ios::app);
    if (!file.is_open()) {
        return false;
    }

    ClassStatistics stats = Statistics::calculateStatistics(students);
    Statistics::writeStatisticsToFile(file, stats);
    file.close();
    return true;
}

bool StudentResultSystem::exportToCSV(const string& filename) const {
    return FileHandler::exportToCSV(filename, students);
}

void StudentResultSystem::processAllStudents() {
    for (Student& student : students) {
        student.calculateResults();
    }
}

void StudentResultSystem::displayResults() const {
    cout << "\nSTUDENT RESULTS REPORT" << endl;
    cout << string(150, '*') << endl;
    cout << left << setw(15) << "Student ID" 
              << setw(25) << "Name" 
              << setw(8) << "Sub1" 
              << setw(8) << "Sub2" 
              << setw(8) << "Sub3" 
              << setw(8) << "Sub4" 
              << setw(8) << "Sub5" 
              << setw(10) << "Total" 
              << setw(12) << "Percentage" 
              << setw(8) << "Grade" 
              << setw(8) << "CGPA" 
              << endl;
    cout << string(150, '*') << endl;

    for (const Student& student : students) {
        student.display();
    }

    cout << string(150, '*') << endl;
}

void StudentResultSystem::displayStatistics() const {
    if (students.empty()) {
        cout << "No students to display statistics." << endl;
        return;
    }
    ClassStatistics stats = Statistics::calculateStatistics(students);
    Statistics::displayStatistics(stats);
}

int StudentResultSystem::getStudentCount() const {
    return students.size();
}

bool StudentResultSystem::isEmpty() const {
    return students.empty();
}

const vector<Student>& StudentResultSystem::getStudents() const {
    return students;
}

ClassStatistics StudentResultSystem::getStatistics() const {
    return Statistics::calculateStatistics(students);
}

void StudentResultSystem::clear() {
    students.clear();
    studentIDs.clear();
}

bool StudentResultSystem::addStudent(const Student& student) {
    // Check for duplicate ID
    if (isDuplicateID(student.getStudentID())) {
        return false;
    }
    students.push_back(student);
    studentIDs.push_back(student.getStudentID());
    return true;
}

bool StudentResultSystem::isDuplicateID(const string& id) const {
    for (const string& existingID : studentIDs) {
        if (existingID == id) {
            return true;
        }
    }
    return false;
}

void StudentResultSystem::parseStudentFromLine(const string& line, int lineNumber) {
    // This method is kept for backward compatibility but not used
    // File parsing is now handled by FileHandler module
}

