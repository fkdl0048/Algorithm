#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> strlist) {
    vector<int> answer;
    for (string str : strlist) {
        answer.push_back(str.length());
    }
    
    return answer;
}