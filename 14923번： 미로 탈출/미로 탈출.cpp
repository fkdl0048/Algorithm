/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 14923                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: fkdl4878 <boj.kr/u/fkdl4878>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/14923                          #+#        #+#      #+#    */
/*   Solved: 2024/06/19 00:56:40 by fkdl4878      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

// 기본적으로 BFS 길찾기 알고리즘

#include <bits/stdc++.h>

using namespace std;

class Maze {
public:
    Maze(int N, int M) : n(N), m(M), grid(N, vector<int>(M)) {}

    void makeMaze() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
    }

    void printMaze() const {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << grid[i][j];
            }
            cout << '\n';
        }
    }

    int solve(int startX, int startY, int endX, int endY) {
        vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(2, false)));
        queue<tuple<int, int, int, int>> q;
        q.push({startX, startY, 0, 0});
        visited[startX][startY][0] = true;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [x, y, dist, wallBroken] = q.front();
            q.pop();

            if (x == endX && y == endY) {
                return dist;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (isValid(nx, ny)) {
                    if (grid[nx][ny] == 0 && !visited[nx][ny][wallBroken]) {
                        visited[nx][ny][wallBroken] = true;
                        q.push({nx, ny, dist + 1, wallBroken});
                    }

                    if (grid[nx][ny] == 1 && wallBroken == 0 && !visited[nx][ny][1]) {
                        visited[nx][ny][1] = true;
                        q.push({nx, ny, dist + 1, 1});
                    }
                }
            }
        }

        return -1;
    }

private:
    vector<vector<int>> grid;
    int n, m;

    bool isValid(int x, int y) const {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
};

int main() {
    int N, M; // 미로 크기
    int Hx, Hy; // 시작 위치
    int Ex, Ey; // 탈출 위치

    cin >> N >> M;
    cin >> Hx >> Hy;
    cin >> Ex >> Ey;

    Maze maze(N, M);
    maze.makeMaze();

    int result = maze.solve(Hx - 1, Hy - 1, Ex - 1, Ey - 1);
    cout << result << endl;

    return 0;
}
