#include "file_handler.h"
#include "validation.h"
#include "grade_calculator.h"
#include "constants.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;
namespace FileHandler {
    int readStudentDataFromFile(const string& filename, 
                                vector<Student>& students,
                                vector<string>& studentIDs) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error: Cannot open file " << filename << endl;
            return 0;
        }

        int count = 0;
        string line;
        int lineNumber = 0;

        while (getline(file, line)) {
            lineNumber++;
            if (line.empty()) continue;

            // Parse line
            vector<string> tokens;
            istringstream iss(line);
            string token;

            while (iss >> token) {
                tokens.push_back(token);
            }

            if (tokens.size() < 6) {  // ID + Name parts + 5 marks
                cerr << "Warning: Line " << lineNumber << " - Insufficient data" << endl;
                continue;
            }

            // Extract Student ID
            string id = tokens[0];
            if (!Validation::isValidID(id)) {
                cerr << "Warning: Line " << lineNumber << " - Invalid Student ID: " << id << endl;
                continue;
            }

            // Check for duplicates
            bool isDuplicate = false;
            for (const string& existingID : studentIDs) {
                if (existingID == id) {
                    isDuplicate = true;
                    break;
                }
            }
            if (isDuplicate) {
                cerr << "Warning: Line " << lineNumber << " - Duplicate Student ID: " << id << endl;
                continue;
            }

            // Extract marks (last 5 tokens)
            int markStartIdx = tokens.size() - 5;
            vector<int> markValues;
            bool validMarks = true;

            for (int i = markStartIdx; i < tokens.size(); i++) {
                try {
                    int mark = stoi(tokens[i]);
                    if (!Validation::isValidMarks(mark)) {
                        cerr << "Warning: Line " << lineNumber << " - Invalid marks: " << mark << endl;
                        validMarks = false;
                        break;
                    }
                    markValues.push_back(mark);
                } catch (...) {
                    validMarks = false;
                    cerr << "Warning: Line " << lineNumber << " - Invalid marks format" << endl;
                    break;
                }
            }

            if (!validMarks || markValues.size() != 5) {
                continue;
            }

            // Extract name
            string name = "";
            for (int i = 1; i < markStartIdx; i++) {
                if (i > 1) name += " ";
                string namePart = tokens[i];
                // Remove quotes if present
                if (namePart.front() == '"') namePart = namePart.substr(1);
                if (namePart.back() == '"') namePart = namePart.substr(0, namePart.length() - 1);
                name += namePart;
            }

            if (!Validation::isValidName(name)) {
                cerr << "Warning: Line " << lineNumber << " - Invalid Name: " << name << endl;
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

    bool writeResultsToFile(const string& filename, 
                           const vector<Student>& students) {
        ofstream file(filename);
        if (!file.is_open()) {
            cerr << "Error: Cannot create output file " << filename << endl;
            return false;
        }

        file << "STUDENT RESULTS REPORT" << endl;
        file << string(150, '*') << endl;

        file << left << setw(15) << "Student ID" 
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

        file << string(150, '*') << endl;

        for (const Student& student : students) {
            student.displayToFile(file);
        }

        file << string(150, '*') << endl;
        file.close();
        return true;
    }

    bool exportToCSV(const string& filename, 
                    const vector<Student>& students) {
        ofstream file(filename);
        if (!file.is_open()) {
            cerr << "Error: Cannot create CSV file " << filename << endl;
            return false;
        }

        // Write CSV header
        file << "Student ID,Name,Sub1,Sub2,Sub3,Sub4,Sub5,Total,Percentage,Grade,CGPA,Status" << endl;

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
                 << fixed << setprecision(2) << student.getPercentage() << ","
                 << student.getGrade() << ","
                 << fixed << setprecision(2) << student.getCGPA() << ","
                 << (student.isPassed() ? "Pass" : "Fail") << endl;
        }

        file.close();
        return true;
    }
}

