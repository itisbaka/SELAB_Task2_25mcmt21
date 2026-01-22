#include "student_result_system.h"
#include "file_handler.h"
#include "statistics.h"
#include "grade_calculator.h"
#include "constants.h"
#include <iostream>
#include <iomanip>
#include <fstream>

StudentResultSystem::StudentResultSystem() {
}

bool StudentResultSystem::loadFromFile(const std::string& filename) {
    students.clear();
    studentIDs.clear();
    int count = FileHandler::readStudentDataFromFile(filename, students, studentIDs);
    return count > 0;
}

bool StudentResultSystem::saveToFile(const std::string& filename) const {
    if (!FileHandler::writeResultsToFile(filename, students)) {
        return false;
    }

    // Append statistics to file
    std::ofstream file(filename, std::ios::app);
    if (!file.is_open()) {
        return false;
    }

    ClassStatistics stats = Statistics::calculateStatistics(students);
    Statistics::writeStatisticsToFile(file, stats);
    file.close();
    return true;
}

bool StudentResultSystem::exportToCSV(const std::string& filename) const {
    return FileHandler::exportToCSV(filename, students);
}

void StudentResultSystem::processAllStudents() {
    for (Student& student : students) {
        student.calculateResults();
    }
}

void StudentResultSystem::displayResults() const {
    std::cout << "\nSTUDENT RESULTS REPORT" << std::endl;
    std::cout << std::string(150, '*') << std::endl;
    std::cout << std::left << std::setw(15) << "Student ID" 
              << std::setw(25) << "Name" 
              << std::setw(8) << "Sub1" 
              << std::setw(8) << "Sub2" 
              << std::setw(8) << "Sub3" 
              << std::setw(8) << "Sub4" 
              << std::setw(8) << "Sub5" 
              << std::setw(10) << "Total" 
              << std::setw(12) << "Percentage" 
              << std::setw(8) << "Grade" 
              << std::setw(8) << "CGPA" 
              << std::endl;
    std::cout << std::string(150, '*') << std::endl;

    for (const Student& student : students) {
        student.display();
    }

    std::cout << std::string(150, '*') << std::endl;
}

void StudentResultSystem::displayStatistics() const {
    if (students.empty()) {
        std::cout << "No students to display statistics." << std::endl;
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

const std::vector<Student>& StudentResultSystem::getStudents() const {
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

bool StudentResultSystem::isDuplicateID(const std::string& id) const {
    for (const std::string& existingID : studentIDs) {
        if (existingID == id) {
            return true;
        }
    }
    return false;
}

void StudentResultSystem::parseStudentFromLine(const std::string& line, int lineNumber) {
    // This method is kept for backward compatibility but not used
    // File parsing is now handled by FileHandler module
}

