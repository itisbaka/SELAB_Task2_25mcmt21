#include "student_result_system.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    string inputFilename = "student_data.txt";
    string outputFilename = "student_results.txt";
    string csvFilename = "student_results.csv";

  
    cout << "  Student Result Processing System v2.0" << endl;
   
    cout << "\nReading student data from: " << inputFilename << endl;

    // Create system instance
    StudentResultSystem system;

    // Load data from file
    if (!system.loadFromFile(inputFilename)) {
        cerr << "\nError: No valid student data found in file!" << endl;
        cerr << "Please ensure the file exists and contains valid data." << endl;
        return 1;
    }

    cout << "Successfully loaded " << system.getStudentCount() << " student record(s)." << endl;

    // Process all students
    cout << "\nProcessing student results..." << endl;
    system.processAllStudents();
    cout << "Processing complete!" << endl;

    // Display results
    system.displayResults();

    // Display statistics
    system.displayStatistics();

    // Save results to text file
    cout << "\nSaving results to: " << outputFilename << endl;
    if (system.saveToFile(outputFilename)) {
        cout << "Results saved successfully!" << endl;
    } else {
        cerr << "Error: Failed to save results to file." << endl;
    }

    // Export to CSV for interoperability
    cout << "\nExporting to CSV format: " << csvFilename << endl;
    if (system.exportToCSV(csvFilename)) {
        cout << "CSV export successful! File can be opened in Excel, Google Sheets, etc." << endl;
    } else {
        cerr << "Error: Failed to export to CSV." << endl;
    }


    cout << "  Processing Complete!" << endl;
  

    return 0;
}

