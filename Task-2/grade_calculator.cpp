#include "grade_calculator.h"
#include "constants.h"

namespace GradeCalculator {
    std::string assignGrade(double percentage) {
        if (percentage >= 90) return "O";
        else if (percentage >= 85) return "A+";
        else if (percentage >= 75) return "A";
        else if (percentage >= 65) return "B+";
        else if (percentage >= 60) return "B";
        else if (percentage >= 55) return "C";
        else if (percentage >= 50) return "D";
        else return "F";
    }

    double calculateCGPA(const std::string& grade) {
        if (grade == "O") return 10.0;
        else if (grade == "A+") return 9.0;
        else if (grade == "A") return 8.0;
        else if (grade == "B+") return 7.5;
        else if (grade == "B") return 7.0;
        else if (grade == "C") return 6.0;
        else if (grade == "D") return 5.0;
        else if (grade == "F") return 0.0;
        else return 0.0;
    }

    int calculateTotalMarks(const int marks[], int size) {
        int total = 0;
        for (int i = 0; i < size; i++) {
            total += marks[i];
        }
        return total;
    }

    double calculatePercentage(int totalMarks, int maxMarks) {
        if (maxMarks == 0) return 0.0;
        return (static_cast<double>(totalMarks) / maxMarks) * 100.0;
    }

    bool checkPassStatus(const int marks[], int size, int passingMarks) {
        for (int i = 0; i < size; i++) {
            if (marks[i] < passingMarks) {
                return false;
            }
        }
        return true;
    }
}

