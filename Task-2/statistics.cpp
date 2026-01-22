#include "statistics.h"
#include <iostream>
#include <iomanip>
#include <fstream>

namespace Statistics {
    ClassStatistics calculateStatistics(const std::vector<Student>& students) {
        ClassStatistics stats = {0};
        
        if (students.empty()) {
            return stats;
        }

        stats.totalStudents = students.size();
        double sumPercentage = 0;
        stats.highestPercentage = students[0].getPercentage();
        stats.lowestPercentage = students[0].getPercentage();

        for (const Student& student : students) {
            double percentage = student.getPercentage();
            sumPercentage += percentage;

            if (percentage > stats.highestPercentage) {
                stats.highestPercentage = percentage;
            }
            if (percentage < stats.lowestPercentage) {
                stats.lowestPercentage = percentage;
            }

            std::string grade = student.getGrade();
            if (grade == "O") stats.gradeCountO++;
            else if (grade == "A+") stats.gradeCountAPlus++;
            else if (grade == "A") stats.gradeCountA++;
            else if (grade == "B+") stats.gradeCountBPlus++;
            else if (grade == "B") stats.gradeCountB++;
            else if (grade == "C") stats.gradeCountC++;
            else if (grade == "D") stats.gradeCountD++;
            else if (grade == "F") stats.gradeCountF++;

            if (student.isPassed()) {
                stats.passedStudents++;
            } else {
                stats.failedStudents++;
            }
        }

        stats.averagePercentage = sumPercentage / students.size();
        return stats;
    }

    void displayStatistics(const ClassStatistics& stats) {
        std::cout << "\nSTATISTICS" << std::endl;
        std::cout << std::string(150, '*') << std::endl;
        std::cout << "Total Students: " << stats.totalStudents << std::endl;
        std::cout << "Class Average Percentage: " << std::fixed << std::setprecision(2) 
                  << stats.averagePercentage << "%" << std::endl;
        std::cout << "Highest Percentage: " << std::fixed << std::setprecision(2) 
                  << stats.highestPercentage << "%" << std::endl;
        std::cout << "Lowest Percentage: " << std::fixed << std::setprecision(2) 
                  << stats.lowestPercentage << "%" << std::endl;
        std::cout << "\nGrade Distribution:" << std::endl;
        std::cout << "  Grade O:  " << stats.gradeCountO << " student(s)" << std::endl;
        std::cout << "  Grade A+: " << stats.gradeCountAPlus << " student(s)" << std::endl;
        std::cout << "  Grade A:  " << stats.gradeCountA << " student(s)" << std::endl;
        std::cout << "  Grade B+: " << stats.gradeCountBPlus << " student(s)" << std::endl;
        std::cout << "  Grade B:  " << stats.gradeCountB << " student(s)" << std::endl;
        std::cout << "  Grade C:  " << stats.gradeCountC << " student(s)" << std::endl;
        std::cout << "  Grade D:  " << stats.gradeCountD << " student(s)" << std::endl;
        std::cout << "  Grade F:  " << stats.gradeCountF << " student(s)" << std::endl;
        std::cout << "\nPass/Fail Statistics:" << std::endl;
        std::cout << "  Passed: " << stats.passedStudents << " student(s)" << std::endl;
        std::cout << "  Failed: " << stats.failedStudents << " student(s)" << std::endl;
        std::cout << std::string(150, '*') << std::endl;
    }

    void writeStatisticsToFile(std::ofstream& file, const ClassStatistics& stats) {
        file << "\n" << std::string(150, '*') << std::endl;
        file << "STATISTICS" << std::endl;
        file << std::string(150, '*') << std::endl;
        file << "Total Students: " << stats.totalStudents << std::endl;
        file << "Class Average Percentage: " << std::fixed << std::setprecision(2) 
             << stats.averagePercentage << "%" << std::endl;
        file << "Highest Percentage: " << std::fixed << std::setprecision(2) 
             << stats.highestPercentage << "%" << std::endl;
        file << "Lowest Percentage: " << std::fixed << std::setprecision(2) 
             << stats.lowestPercentage << "%" << std::endl;
        file << "\nGrade Distribution:" << std::endl;
        file << "  Grade O:  " << stats.gradeCountO << " student(s)" << std::endl;
        file << "  Grade A+: " << stats.gradeCountAPlus << " student(s)" << std::endl;
        file << "  Grade A:  " << stats.gradeCountA << " student(s)" << std::endl;
        file << "  Grade B+: " << stats.gradeCountBPlus << " student(s)" << std::endl;
        file << "  Grade B:  " << stats.gradeCountB << " student(s)" << std::endl;
        file << "  Grade C:  " << stats.gradeCountC << " student(s)" << std::endl;
        file << "  Grade D:  " << stats.gradeCountD << " student(s)" << std::endl;
        file << "  Grade F:  " << stats.gradeCountF << " student(s)" << std::endl;
        file << "\nPass/Fail Statistics:" << std::endl;
        file << "  Passed: " << stats.passedStudents << " student(s)" << std::endl;
        file << "  Failed: " << stats.failedStudents << " student(s)" << std::endl;
        file << std::string(150, '*') << std::endl;
    }
}

