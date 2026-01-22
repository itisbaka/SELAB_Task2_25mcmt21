#include "file_handler.h"
#include "validation.h"
#include "grade_calculator.h"
#include "constants.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

namespace FileHandler {
    int readStudentDataFromFile(const std::string& filename, 
                                std::vector<Student>& students,
                                std::vector<std::string>& studentIDs) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: Cannot open file " << filename << std::endl;
            return 0;
        }

        int count = 0;
        std::string line;
        int lineNumber = 0;

        while (std::getline(file, line)) {
            lineNumber++;
            if (line.empty()) continue;

            // Parse line
            std::vector<std::string> tokens;
            std::istringstream iss(line);
            std::string token;

            while (iss >> token) {
                tokens.push_back(token);
            }

            if (tokens.size() < 6) {  // ID + Name parts + 5 marks
                std::cerr << "Warning: Line " << lineNumber << " - Insufficient data" << std::endl;
                continue;
            }

            // Extract Student ID
            std::string id = tokens[0];
            if (!Validation::isValidID(id)) {
                std::cerr << "Warning: Line " << lineNumber << " - Invalid Student ID: " << id << std::endl;
                continue;
            }

            // Check for duplicates
            bool isDuplicate = false;
            for (const std::string& existingID : studentIDs) {
                if (existingID == id) {
                    isDuplicate = true;
                    break;
                }
            }
            if (isDuplicate) {
                std::cerr << "Warning: Line " << lineNumber << " - Duplicate Student ID: " << id << std::endl;
                continue;
            }

            // Extract marks (last 5 tokens)
            int markStartIdx = tokens.size() - 5;
            std::vector<int> markValues;
            bool validMarks = true;

            for (int i = markStartIdx; i < tokens.size(); i++) {
                try {
                    int mark = std::stoi(tokens[i]);
                    if (!Validation::isValidMarks(mark)) {
                        std::cerr << "Warning: Line " << lineNumber << " - Invalid marks: " << mark << std::endl;
                        validMarks = false;
                        break;
                    }
                    markValues.push_back(mark);
                } catch (...) {
                    validMarks = false;
                    std::cerr << "Warning: Line " << lineNumber << " - Invalid marks format" << std::endl;
                    break;
                }
            }

            if (!validMarks || markValues.size() != 5) {
                continue;
            }

            // Extract name
            std::string name = "";
            for (int i = 1; i < markStartIdx; i++) {
                if (i > 1) name += " ";
                std::string namePart = tokens[i];
                // Remove quotes if present
                if (namePart.front() == '"') namePart = namePart.substr(1);
                if (namePart.back() == '"') namePart = namePart.substr(0, namePart.length() - 1);
                name += namePart;
            }

            if (!Validation::isValidName(name)) {
                std::cerr << "Warning: Line " << lineNumber << " - Invalid Name: " << name << std::endl;
                continue;
            }

            // Create student
            int marksArray[SUBJECTS];
            for (int i = 0; i < SUBJECTS; i++) {
                marksArray[i] = markValues[i];
            }

            Student student(id, name, marksArray);
            students.push_back(student);
            studentIDs.push_back(id);
            count++;
        }

        file.close();
        return count;
    }

    bool writeResultsToFile(const std::string& filename, 
                           const std::vector<Student>& students) {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: Cannot create output file " << filename << std::endl;
            return false;
        }

        file << "STUDENT RESULTS REPORT" << std::endl;
        file << std::string(150, '*') << std::endl;

        file << std::left << std::setw(15) << "Student ID" 
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

        file << std::string(150, '*') << std::endl;

        for (const Student& student : students) {
            student.displayToFile(file);
        }

        file << std::string(150, '*') << std::endl;
        file.close();
        return true;
    }

    bool exportToCSV(const std::string& filename, 
                    const std::vector<Student>& students) {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: Cannot create CSV file " << filename << std::endl;
            return false;
        }

        // Write CSV header
        file << "Student ID,Name,Sub1,Sub2,Sub3,Sub4,Sub5,Total,Percentage,Grade,CGPA,Status" << std::endl;

        // Write data
        for (const Student& student : students) {
            file << student.getStudentID() << ","
                 << "\"" << student.getName() << "\","
                 << student.getMark(0) << ","
                 << student.getMark(1) << ","
                 << student.getMark(2) << ","
                 << student.getMark(3) << ","
                 << student.getMark(4) << ","
                 << student.getTotalMarks() << ","
                 << std::fixed << std::setprecision(2) << student.getPercentage() << ","
                 << student.getGrade() << ","
                 << std::fixed << std::setprecision(2) << student.getCGPA() << ","
                 << (student.isPassed() ? "Pass" : "Fail") << std::endl;
        }

        file.close();
        return true;
    }
}

