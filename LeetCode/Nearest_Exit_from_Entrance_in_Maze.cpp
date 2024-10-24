class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int row = maze.size();
        int col = maze[0].size();
        int steps = 0;

        vector<vector<bool>> visited(row, vector<bool>(col, false));
        queue<pair<int, int>> q;

        int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int startX = entrance[1];
        int startY = entrance[0];

        visited[startY][startX] = true;
        q.push({startY, startX});

        while(!q.empty()) {
            int n = q.size();
            steps++;

            for (int i = 0; i < n; i++) {
                auto[y, x] = q.front();
                q.pop();

                for (auto& dir : dirs) {
                    int nx = x + dir[1];
                    int ny = y + dir[0];

                    if (nx >= 0 && nx < col && ny >=0 && ny < row 
                    && maze[ny][nx] == '.' && visited[ny][nx] == false) {
                        if (nx == 0 || nx == col - 1 || ny == 0 || ny == row - 1) {
                            if (!(nx == startX && ny == startY)) {
                                return steps;
                            }
                        }

                        visited[ny][nx] = true;
                        q.push({ny, nx});
                    }
                }
            }
        }

        return -1;
    }
};
