#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <string>
#include <vector>
#include "student.h"

/**
 * @namespace FileHandler
 * @brief Provides file I/O operations for student data
 * 
 * Module Characteristics:
 * - Name: File Handler Module
 * - Cohesion: High (all functions handle file operations)
 * - Coupling: Low (depends only on Student class)
 * - Interoperability: Can read/write data in standard formats
 */
namespace FileHandler {
    /**
     * @brief Reads student data from a file
     * @param filename Input file path
     * @param students Vector to store parsed students
     * @param studentIDs Vector to track student IDs (for duplicate checking)
     * @return Number of successfully parsed students
     */
    int readStudentDataFromFile(const std::string& filename, 
                                std::vector<Student>& students,
                                std::vector<std::string>& studentIDs);

    /**
     * @brief Writes student results to a file
     * @param filename Output file path
     * @param students Vector of students to write
     * @return true if successful, false otherwise
     */
    bool writeResultsToFile(const std::string& filename, 
                           const std::vector<Student>& students);

    /**
     * @brief Exports student data to CSV format
     * @param filename Output CSV file path
     * @param students Vector of students to export
     * @return true if successful, false otherwise
     */
    bool exportToCSV(const std::string& filename, 
                    const std::vector<Student>& students);
}

#endif // FILE_HANDLER_H

