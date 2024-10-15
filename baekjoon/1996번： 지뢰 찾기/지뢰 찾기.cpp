/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1996                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: fkdl4878 <boj.kr/u/fkdl4878>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1996                           #+#        #+#      #+#    */
/*   Solved: 2024/06/18 22:10:28 by fkdl4878      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

// NxN 칸의 지뢰판이 존재
// 지뢰는 한 칸에 한 개 이상 존재 가능 (즉, 숫자로 입력 받음)
// 지뢰가 아닌 칸은 .으로 입력받고 출력은 주위 지뢰의 개수를 출력
// 9개 이상이라면 M으로 출력하라

#include <bits/stdc++.h>

using namespace std;

pair<int, int> dir[8] = {{1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}};

vector<vector<char>> searchBoom(const vector<vector<char>> &v)
{
    int n = v.size();

    vector<vector<char>> res (n, vector<char>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isdigit(v[i][j]))
                res[i][j] = '*';
            else
            {
                res[i][j] = '0';
                for (auto p : dir)
                {
                    int nx = p.first + j;
                    int ny = p.second + i;

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        continue;
                    
                    if (isdigit(v[ny][nx]))
                        res[i][j] += v[ny][nx] - '0';
                    if (res[i][j] > '9')
                        res[i][j] = 'M';
                }
            }
        }
    }

    return res;
}

int main()
{
    int n;

    cin >> n;
    vector<vector<char>> v(n, vector<char>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }

    auto res = searchBoom(v);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << res[i][j];
        }
        cout << '\n';
    }
}