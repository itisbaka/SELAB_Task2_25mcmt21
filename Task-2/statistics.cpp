#include "statistics.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

namespace Statistics {
    ClassStatistics calculateStatistics(const vector<Student>& students) {
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

            string grade = student.getGrade();
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
        cout << "\nSTATISTICS" << endl;
        cout << string(150, '*') << endl;
        cout << "Total Students: " << stats.totalStudents << endl;
        cout << "Class Average Percentage: " << fixed << setprecision(2) 
                  << stats.averagePercentage << "%" << endl;
        cout << "Highest Percentage: " << fixed << setprecision(2) 
                  << stats.highestPercentage << "%" << endl;
        cout << "Lowest Percentage: " << fixed << setprecision(2) 
                  << stats.lowestPercentage << "%" << endl;
        cout << "\nGrade Distribution:" << endl;
        cout << "  Grade O:  " << stats.gradeCountO << " student(s)" << endl;
        cout << "  Grade A+: " << stats.gradeCountAPlus << " student(s)" << endl;
        cout << "  Grade A:  " << stats.gradeCountA << " student(s)" << endl;
        cout << "  Grade B+: " << stats.gradeCountBPlus << " student(s)" << endl;
        cout << "  Grade B:  " << stats.gradeCountB << " student(s)" << endl;
        cout << "  Grade C:  " << stats.gradeCountC << " student(s)" << endl;
        cout << "  Grade D:  " << stats.gradeCountD << " student(s)" << endl;
        cout << "  Grade F:  " << stats.gradeCountF << " student(s)" << endl;
        cout << "\nPass/Fail Statistics:" << endl;
        cout << "  Passed: " << stats.passedStudents << " student(s)" << endl;
        cout << "  Failed: " << stats.failedStudents << " student(s)" << endl;
        cout << string(150, '*') << endl;
    }

    void writeStatisticsToFile(ofstream& file, const ClassStatistics& stats) {
        file << "\n" << string(150, '*') << endl;
        file << "STATISTICS" << endl;
        file << string(150, '*') << endl;
        file << "Total Students: " << stats.totalStudents << endl;
        file << "Class Average Percentage: " << fixed << setprecision(2) 
             << stats.averagePercentage << "%" << endl;
        file << "Highest Percentage: " << fixed << setprecision(2) 
             << stats.highestPercentage << "%" << endl;
        file << "Lowest Percentage: " << fixed << setprecision(2) 
             << stats.lowestPercentage << "%" << endl;
        file << "\nGrade Distribution:" << endl;
        file << "  Grade O:  " << stats.gradeCountO << " student(s)" << endl;
        file << "  Grade A+: " << stats.gradeCountAPlus << " student(s)" << endl;
        file << "  Grade A:  " << stats.gradeCountA << " student(s)" << endl;
        file << "  Grade B+: " << stats.gradeCountBPlus << " student(s)" << endl;
        file << "  Grade B:  " << stats.gradeCountB << " student(s)" << endl;
        file << "  Grade C:  " << stats.gradeCountC << " student(s)" << endl;
        file << "  Grade D:  " << stats.gradeCountD << " student(s)" << endl;
        file << "  Grade F:  " << stats.gradeCountF << " student(s)" << endl;
        file << "\nPass/Fail Statistics:" << endl;
        file << "  Passed: " << stats.passedStudents << " student(s)" << endl;
        file << "  Failed: " << stats.failedStudents << " student(s)" << endl;
        file << string(150, '*') << endl;
    }
}

