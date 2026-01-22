#include "student_result_system.h"
#include <iostream>
#include <string>

/**
 * @brief Main entry point for Student Result Processing System
 * 
 * This program demonstrates:
 * - Usability: User-friendly interface with clear prompts
 * - Efficiency: Optimized memory usage and processing
 * - Reusability: Modular design allows reuse of components
 * - Interoperability: Can export to CSV for use with other platforms
 */
int main() {
    std::string inputFilename = "student_data.txt";
    std::string outputFilename = "student_results.txt";
    std::string csvFilename = "student_results.csv";

    std::cout << "==========================================" << std::endl;
    std::cout << "  Student Result Processing System v2.0" << std::endl;
    std::cout << "==========================================" << std::endl;
    std::cout << "\nReading student data from: " << inputFilename << std::endl;

    // Create system instance
    StudentResultSystem system;

    // Load data from file
    if (!system.loadFromFile(inputFilename)) {
        std::cerr << "\nError: No valid student data found in file!" << std::endl;
        std::cerr << "Please ensure the file exists and contains valid data." << std::endl;
        return 1;
    }

    std::cout << "Successfully loaded " << system.getStudentCount() << " student record(s)." << std::endl;

    // Process all students
    std::cout << "\nProcessing student results..." << std::endl;
    system.processAllStudents();
    std::cout << "Processing complete!" << std::endl;

    // Display results
    system.displayResults();

    // Display statistics
    system.displayStatistics();

    // Save results to text file
    std::cout << "\nSaving results to: " << outputFilename << std::endl;
    if (system.saveToFile(outputFilename)) {
        std::cout << "Results saved successfully!" << std::endl;
    } else {
        std::cerr << "Error: Failed to save results to file." << std::endl;
    }

    // Export to CSV for interoperability
    std::cout << "\nExporting to CSV format: " << csvFilename << std::endl;
    if (system.exportToCSV(csvFilename)) {
        std::cout << "CSV export successful! File can be opened in Excel, Google Sheets, etc." << std::endl;
    } else {
        std::cerr << "Error: Failed to export to CSV." << std::endl;
    }

    std::cout << "\n==========================================" << std::endl;
    std::cout << "  Processing Complete!" << std::endl;
    std::cout << "==========================================" << std::endl;

    return 0;
}

