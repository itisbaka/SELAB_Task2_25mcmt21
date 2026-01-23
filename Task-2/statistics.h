#ifndef STATISTICS_H
#define STATISTICS_H

#include <string>
#include <vector>
#include <fstream>
#include "student.h"
using namespace std;

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


namespace Statistics {
  
    ClassStatistics calculateStatistics(const vector<Student>& students);


    void displayStatistics(const ClassStatistics& stats);

  
    void writeStatisticsToFile(ofstream& file, const ClassStatistics& stats);
}

#endif 

