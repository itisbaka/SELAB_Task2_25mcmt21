#ifndef STUDENT_RESULT_SYSTEM_H
#define STUDENT_RESULT_SYSTEM_H

#include <vector>
#include <string>
#include "student.h"
#include "statistics.h"
using namespace std;

class StudentResultSystem {
private:
    vector<Student> students;
    vector<string> studentIDs;

    bool isDuplicateID(const string& id) const;
    void parseStudentFromLine(const string& line, int lineNumber);

public:
    // Constructor
    StudentResultSystem();

    // File operations
    bool loadFromFile(const string& filename);
    bool saveToFile(const string& filename) const;
    bool exportToCSV(const string& filename) const;

    // Operations
    void processAllStudents();
    void displayResults() const;
    void displayStatistics() const;

    // Getters
    int getStudentCount() const;
    bool isEmpty() const;
    const vector<Student>& getStudents() const;
    ClassStatistics getStatistics() const;

    // Utility
    void clear();
    bool addStudent(const Student& student);
};

#endif 

