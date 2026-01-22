#ifndef STUDENT_RESULT_SYSTEM_H
#define STUDENT_RESULT_SYSTEM_H

#include <vector>
#include <string>
#include "student.h"
#include "statistics.h"

/**
 * @class StudentResultSystem
 * @brief Main system class for managing student results
 * 
 * This class orchestrates all operations including reading data, processing,
 * displaying results, and generating statistics.
 * 
 * Module Characteristics:
 * - Name: Student Result System Module
 * - Cohesion: High (all methods manage student result operations)
 * - Coupling: Low (uses other modules through well-defined interfaces)
 */
class StudentResultSystem {
private:
    std::vector<Student> students;
    std::vector<std::string> studentIDs;

    bool isDuplicateID(const std::string& id) const;
    void parseStudentFromLine(const std::string& line, int lineNumber);

public:
    // Constructor
    StudentResultSystem();

    // File operations
    bool loadFromFile(const std::string& filename);
    bool saveToFile(const std::string& filename) const;
    bool exportToCSV(const std::string& filename) const;

    // Operations
    void processAllStudents();
    void displayResults() const;
    void displayStatistics() const;

    // Getters
    int getStudentCount() const;
    bool isEmpty() const;
    const std::vector<Student>& getStudents() const;
    ClassStatistics getStatistics() const;

    // Utility
    void clear();
    bool addStudent(const Student& student);
};

#endif // STUDENT_RESULT_SYSTEM_H

