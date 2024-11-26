#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

bool isVaildQuiz(string quiz) {
    stringstream ss(quiz);
    int x, y, z;
    char op, equal_sign;
    
    ss >> x >> op >> y >> equal_sign >> z;
    
    if (op == '+') {
        if ((x + y) == z) {
            return true;
        } else {
            return false;
        }
    } else if (op == '-') {
        if ((x - y) == z) {
            return true;
        } else {
            return false;
        }
    }
    
    return false;
}

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    
    for (string str : quiz) {
        if (isVaildQuiz(str)) {
            answer.push_back("O");
        } else {
            answer.push_back("X");
        }
    }
    
    return answer;
}