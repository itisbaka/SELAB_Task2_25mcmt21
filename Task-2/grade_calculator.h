#ifndef GRADE_CALCULATOR_H
#define GRADE_CALCULATOR_H

#include <string>

/**
 * @namespace GradeCalculator
 * @brief Provides functions for grade and CGPA calculations
 * 
 * Module Characteristics:
 * - Name: Grade Calculator Module
 * - Cohesion: High (all functions related to grade/CGPA calculation)
 * - Coupling: Low (only uses standard library)
 * - Reusability: High (can be used in any grading system)
 */
namespace GradeCalculator {
    /**
     * @brief Assigns grade based on percentage
     * @param percentage Student's percentage
     * @return Grade string (O, A+, A, B+, B, C, D, F)
     */
    std::string assignGrade(double percentage);

    /**
     * @brief Calculates CGPA based on grade
     * @param grade Grade string
     * @return CGPA value (0.0 to 10.0)
     */
    double calculateCGPA(const std::string& grade);

    /**
     * @brief Calculates total marks from marks array
     * @param marks Array of marks
     * @param size Size of the array
     * @return Total marks
     */
    int calculateTotalMarks(const int marks[], int size);

    /**
     * @brief Calculates percentage from total marks
     * @param totalMarks Total marks obtained
     * @param maxMarks Maximum possible marks
     * @return Percentage value
     */
    double calculatePercentage(int totalMarks, int maxMarks);

    /**
     * @brief Checks if student passed (all subjects >= passing marks)
     * @param marks Array of marks
     * @param size Size of the array
     * @param passingMarks Minimum marks required to pass
     * @return true if passed, false otherwise
     */
    bool checkPassStatus(const int marks[], int size, int passingMarks);
}

#endif // GRADE_CALCULATOR_H

