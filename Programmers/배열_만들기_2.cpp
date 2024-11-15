#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    
    for (int i = l; i <= r; i++) {
        string str = to_string(i);
        bool flag = true;
        
        for (char c : str) {
            if (c != '0' && c != '5') {
                flag = false;
                break;
            }
        }
        
        if (flag) {
            answer.push_back(i);
        }
    }
    
    if (answer.empty()) {
        answer.push_back(-1);
    }
    
    return answer;
}