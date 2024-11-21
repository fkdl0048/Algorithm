#include <string>
#include <vector>

using namespace std;

string solution(int age) {
    string answer = "";
    
    for (char c : to_string(age)) {
        answer += '0' + c + 1;
    }
    
    return answer;
}