class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int fresh = 0;
        int minutes = 0;

        queue<pair<int, int>> q;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        while (!q.empty() && fresh > 0) {
            int n = q.size();
            minutes++;

            for (int i = 0; i < n; i++) {
                auto[x, y] = q.front();
                q.pop();

                for (auto dir : dirs) {
                    int nx = x + dir[0];
                    int ny = y + dir[1];

                    if (nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        fresh--;
                    }
                }
            }
        }

        return fresh == 0 ? minutes : -1;
    }
};
