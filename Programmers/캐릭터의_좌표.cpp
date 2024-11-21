#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 가로가 7
// -3 -2 -1 0 1 2 3

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer(2, 0);
    unordered_map<string, pair<int, int>> m = {
        {"left", {-1, 0}},
        {"right", {1, 0}},
        {"up", {0, 1}},
        {"down", {0, -1}}
    };
    
    for (const string& key : keyinput) {
        auto dir = m[key];
        int nx = answer[0] + dir.first;
        int ny = answer[1] + dir.second;
        
        if (nx >= -(board[0] / 2) &&
            nx <= (board[0] / 2) &&
            ny >= -(board[1] / 2) &&
            ny <= (board[1] / 2) ) {
            answer[0] = nx;
            answer[1] = ny;
        }
    }
    
    return answer;
}