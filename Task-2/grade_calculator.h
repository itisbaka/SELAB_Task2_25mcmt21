#ifndef GRADE_CALCULATOR_H
#define GRADE_CALCULATOR_H

#include <string>
using namespace std;

namespace GradeCalculator {

    string assignGrade(double percentage);

   
    double calculateCGPA(const string& grade);

 
    int calculateTotalMarks(const int marks[], int size);

  
    double calculatePercentage(int totalMarks, int maxMarks);


    bool checkPassStatus(const int marks[], int size, int passingMarks);
}

#endif 

