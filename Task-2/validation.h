#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>

/**
 * @namespace Validation
 * @brief Provides validation functions for student data
 * 
 * Module Characteristics:
 * - Name: Validation Module
 * - Cohesion: High (all functions validate different aspects of student data)
 * - Coupling: Low (no dependencies on other modules)
 * - Reusability: High (can be used in any application requiring student data validation)
 */
namespace Validation {
    /**
     * @brief Validates student ID format
     * @param id Student ID to validate
     * @return true if valid (alphanumeric, non-empty), false otherwise
     */
    bool isValidID(const std::string& id);

    /**
     * @brief Validates student name format
     * @param name Student name to validate
     * @return true if valid (only alphabets and spaces), false otherwise
     */
    bool isValidName(const std::string& name);

    /**
     * @brief Validates marks range
     * @param mark Mark value to validate
     * @return true if valid (0-100), false otherwise
     */
    bool isValidMarks(int mark);

    /**
     * @brief Validates all marks in an array
     * @param marks Array of marks
     * @param size Size of the array
     * @return true if all marks are valid, false otherwise
     */
    bool isValidMarksArray(const int marks[], int size);
}

#endif // VALIDATION_H

