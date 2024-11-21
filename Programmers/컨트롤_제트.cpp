#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

int solution(string s) {
    string code;
    stringstream ss(s);
    int prevNum = 0;
    int answer = 0;
    
    while (ss >> code) {
        if (code == "Z") {
            answer -= prevNum;
        } else {
            int num = stoi(code);
            prevNum = num;
            answer += num;
        }
    }
    
    return answer;
}