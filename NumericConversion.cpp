/*
 * File: NumericConversion.cpp
 * ---------------------------
 * Name: [TODO: Amy R. Weiner]
 * Section: [TODO: enter section leader here]
 * This program implements the functions intToString 
 * and stringToInt by employing recursion.
 */

#include <iostream>
#include <string>
#include "simpio.h"
#include "console.h"
#include <math.h>
using namespace std;

/* Function prototypes */
string intToString(int n);
string digitToString(int n);
int stringToInt(string str);
int characterToInt(char ch);


/* Main program */
int main() {
    int n = getInteger("Please enter an integer: ");
    string toString = intToString(n);
    cout << "The integer " << n << " as a string is: " << toString << endl;
    string str = getLine("Please enter a string of integers: ");
    int toInteger = stringToInt(str);
    cout << "The string " << str << " as an integer is: " << toInteger << endl;
   return 0;
}

/* Function: intToString
 * Usage: string str = intToString(int n);
 * ---------------------------------------
 * This function returns the result of
 * converting an integer n into a string 
 * str of integers. 
 */
string intToString(int n) {
    if (abs(n) < 10) {
        return digitToString(n);
    }else {
        int m = abs(n % 10);
        return intToString(n / 10) + digitToString(m);
    }
}

/* Function: digitToString
 * Usage: string str = digitToString(int n);
 * -----------------------------------------
 * This function returns the result of
 * converting a single digit n of an integer
 * into a string str.
 */
string digitToString(int n) {
    if (n >= 0) {
        string result = "";
        n += 48;
        return result += n;
    } else {
        n = abs(n); 
        string result = "-";
        n += 48;
        return result += n;
    }
}


/* Function: stringToInt
 * Usage: int n = stringToInt(string str);
 * ---------------------------------------
 * This function returns the result of
 * converting a string str of integers
 * into an integer n. 
 */
int stringToInt(string str) {
    if (str.length() == 1) {
        return characterToInt(str.at(0));
    } else {
        if (str.at(0) == '-') {
            str = str.substr(1);
            if (str.length() == 1) {
                return - (characterToInt(str.at(0)));
            }
            return -(characterToInt(str.at(0)) * pow(10, str.length() - 1)) - stringToInt(str.substr(1));
        }
        return (characterToInt(str.at(0)) * pow(10, str.length() - 1)) + stringToInt(str.substr(1));
    }
}

/* Function: characterToInt
 * Usage: int n = characterToInt(char ch);
 * ---------------------------------------
 * This function returns the result of
 * converting a single character ch into
 * an integer n. 
 */
int characterToInt(char ch) {
    int n = ch;
    n -= 48;
    return n;
}




