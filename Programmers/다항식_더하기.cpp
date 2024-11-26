#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

bool isLinear(string str) {
    for (char c : str) {
        if (c == 'x') {
            return true;
        }
    }
    
    return false;
}

int getNumber(string str) {
    int result = 0;
    
    for (char c : str) {
        if (isdigit(c)) {
            result = result * 10 + (c - '0');
        }
    }
    
    return result;
}

string solution(string polynomial) {
    int linear = 0;
    int num = 0;
    string code;
    stringstream ss(polynomial);
    while (ss >> code) {
        if (code != "+") {
            if (isLinear(code)) {
                linear += getNumber(code);
                if (code.length() == 1) {
                    linear++;
                }
            } else {
                num += getNumber(code);
            }
        }
    }
    
    string linearStr = "";
    if (linear == 1) {
        linearStr = "x";
    } else {
        linearStr = to_string(linear) + "x";
    }
    
    if (linear != 0 && num != 0) {
        return linearStr + " + " + to_string(num);
    } else if (linear != 0) {
        return linearStr;
    } else {
        return to_string(num);
    }
}