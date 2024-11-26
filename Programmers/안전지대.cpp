#include <string>
#include <vector>

using namespace std;

const vector<pair<int, int>> directions = {
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -1},          {0, 1},
    {1, -1}, {1, 0}, {1, 1}
};

int solution(vector<vector<int>> board) {
    int n = board.size();
    vector<vector<bool>> dangerZone(n, vector<bool>(n, false));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 1) {
                dangerZone[i][j] = true;
                for (const auto& dir : directions) {
                    int ni = i + dir.first;
                    int nj = j + dir.second;
                    if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                        dangerZone[ni][nj] = true;
                    }
                }
            }
        }
    }

    int safeCount = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!dangerZone[i][j]) {
                ++safeCount;
            }
        }
    }

    return safeCount;
}