#include "validation.h"
#include <cctype>
using namespace std;
namespace Validation {
    bool isValidID(const string& id) {
        if (id.empty()) return false;
        for (char c : id) {
            if (!isalnum(c)) {
                return false;
            }
        }
        return true;
    }

    bool isValidName(const string& name) {
        if (name.empty()) return false;
        for (char c : name) {
            if (!isalpha(c) && c != ' ') {
                return false;
            }
        }
        return true;
    }

    bool isValidMarks(int mark) {
        return (mark >= 0 && mark <= 100);
    }

    bool isValidMarksArray(const int marks[], int size) {
        for (int i = 0; i < size; i++) {
            if (!isValidMarks(marks[i])) {
                return false;
            }
        }
        return true;
    }
}

