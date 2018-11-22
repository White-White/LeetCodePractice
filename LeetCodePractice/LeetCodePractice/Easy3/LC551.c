/*
 You are given a string representing an attendance record for a student. The record only contains the following three characters:
 'A' : Absent.
 'L' : Late.
 'P' : Present.
 A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).
 
 You need to return whether the student could be rewarded according to his attendance record.
 
 Example 1:
 Input: "PPALLP"
 Output: True
 Example 2:
 Input: "PPALLL"
 Output: False
 */

#include "LC551.h"

bool checkRecord(char* s) {
    
    int len = (int)strlen(s);
    
    int countA = 0;
    int countContinuousL = 0;
    
    for (int i = 0; i < len; i++) {
        switch (s[i]) {
            case 'A': {
                countContinuousL = 0;
                countA++;
                if (countA >= 2) {
                    return false;
                }
            }
                break;
            case 'L': {
                countContinuousL++;
                if (countContinuousL >= 3) {
                    return false;
                }
            }
                break;
            default: {
                countContinuousL = 0;
            }
                break;
        }
    }
    
    return true;
    
}
