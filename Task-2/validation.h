#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>
using namespace std;

namespace Validation {
  
    bool isValidID(const string& id);

  
    bool isValidName(const string& name);

  
    bool isValidMarks(int mark);


    bool isValidMarksArray(const int marks[], int size);
}

#endif 
