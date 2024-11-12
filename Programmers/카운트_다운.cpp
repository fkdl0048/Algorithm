#include <string>
#include <vector>

using namespace std;

vector<int> solution(int start_num, int end_num) {
    vector<int> answer;
    
    while (start_num >= end_num) {
        answer.push_back(start_num);
        start_num--;
    }
    
    return answer;
}