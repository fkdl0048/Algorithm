#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (vector<int> command : commands) {
        vector<int> list(array.begin() + command[0] - 1, array.begin() + command[1]);
        sort(list.begin(), list.end());
        answer.push_back(list[command[2] - 1]);
    }
    
    return answer;
}