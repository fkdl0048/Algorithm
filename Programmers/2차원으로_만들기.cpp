#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    int size = num_list.size() / n;
    vector<vector<int>> answer(size, vector<int>(n, 0));
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < n; j++) {
            answer[i][j] = num_list[i*n + j];
        }
    }
    
    return answer;
}