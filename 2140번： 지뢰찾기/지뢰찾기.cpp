/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2140                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: fkdl4878 <boj.kr/u/fkdl4878>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2140                           #+#        #+#      #+#    */
/*   Solved: 2024/06/18 22:58:59 by fkdl4878      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

// 정사각형 N*N
// 지뢰가 없는 칸에는 인접한 지뢰의 수
// 지뢰 경우의 수 세는 문제

// 1. 테투리가 열려져 있는 지뢰판이 존재
// 2. 해당 지뢰판에서 몇개의 칸에 최대 몇개의 지뢰가 존재하는지

#include <bits/stdc++.h>

using namespace std;

pair<int, int> dir[8] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

bool solve(int x, int y, vector<vector<char>> &v) {
    int len = v.size();

    if (isdigit(v[x][y])) return false;

    for (int i = 0; i < 8; i++) {
        int nx = x + dir[i].first;
        int ny = y + dir[i].second;

        if (nx < 0 || nx >= len || ny < 0 || ny >= len)
            continue;

        if (v[nx][ny] == '0') {
            return false;
        }
    }

    for (int i = 0; i < 8; i++) {
        int nx = x + dir[i].first;
        int ny = y + dir[i].second;

        if (nx < 0 || nx >= len || ny < 0 || ny >= len)
            continue;

        if (isdigit(v[nx][ny])) {
            v[nx][ny]--;
        }
    }

    v[x][y] = '*';
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<vector<char>> v(n, vector<char>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    int mineCount = 0;

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (solve(i, j, v)) {
                mineCount++;
            }
        }
    }
    
    cout << mineCount << endl;

    return 0;
}