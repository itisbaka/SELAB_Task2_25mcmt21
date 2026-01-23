#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <string>
#include <vector>
#include "student.h"
using namespace std;

namespace FileHandler {
    
    int readStudentDataFromFile(const string& filename, 
                                vector<Student>& students,
                                vector<string>& studentIDs);

    /**
     * @brief Writes student results to a file
     * @param filename Output file path
     * @param students Vector of students to write
     * @return true if successful, false otherwise
     */
    bool writeResultsToFile(const string& filename, 
                           const vector<Student>& students);

    /**
     * @brief Exports student data to CSV format
     * @param filename Output CSV file path
     * @param students Vector of students to export
     * @return true if successful, false otherwise
     */
    bool exportToCSV(const string& filename, 
                    const vector<Student>& students);
}

#endif 

