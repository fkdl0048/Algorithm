#include <string>
#include <vector>
#include <climits>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    
    for (const auto& pair : queries) {
        int min_val = INT_MAX;
        
        for (int i = pair[0]; i <= pair[1]; i++) {
            if (arr[i] > pair[2]) {
               min_val = min(min_val, arr[i]);
            }
        }
        
        answer.push_back(min_val == INT_MAX ? -1 : min_val);
    }
    
    return answer;
}