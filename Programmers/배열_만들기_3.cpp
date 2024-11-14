#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> intervals) {
    vector<int> answer;
    
    for (int i = 0; i < intervals.size(); i++) {
        for (int j = intervals[i][0]; j <= intervals[i][1]; j++) {
            answer.push_back(arr[j]);
        }
    }
    
    return answer;
}