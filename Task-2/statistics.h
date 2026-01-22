#ifndef STATISTICS_H
#define STATISTICS_H

#include <string>
#include <vector>
#include <fstream>
#include "student.h"

/**
 * @struct ClassStatistics
 * @brief Structure to hold class statistics
 */
struct ClassStatistics {
    double averagePercentage;
    double highestPercentage;
    double lowestPercentage;
    int gradeCountO;
    int gradeCountAPlus;
    int gradeCountA;
    int gradeCountBPlus;
    int gradeCountB;
    int gradeCountC;
    int gradeCountD;
    int gradeCountF;
    int totalStudents;
    int passedStudents;
    int failedStudents;
};

/**
 * @namespace Statistics
 * @brief Provides statistical analysis functions for student results
 * 
 * Module Characteristics:
 * - Name: Statistics Module
 * - Cohesion: High (all functions calculate statistics)
 * - Coupling: Low (depends only on Student class)
 * - Reusability: High (can be used for any statistical analysis)
 */
namespace Statistics {
    /**
     * @brief Calculates comprehensive class statistics
     * @param students Vector of students
     * @return ClassStatistics structure with all calculated values
     */
    ClassStatistics calculateStatistics(const std::vector<Student>& students);

    /**
     * @brief Displays statistics to console
     * @param stats ClassStatistics structure
     */
    void displayStatistics(const ClassStatistics& stats);

    /**
     * @brief Writes statistics to file
     * @param file Output file stream
     * @param stats ClassStatistics structure
     */
    void writeStatisticsToFile(std::ofstream& file, const ClassStatistics& stats);
}

#endif // STATISTICS_H

