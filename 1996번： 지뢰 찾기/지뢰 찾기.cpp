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

// N*N의 맵 (정사각형)
// 각 칸에 숫자나 지뢰
// 각 칸의 숫자는 8방향으로 인접한 지뢰의 개수를 나타냄
// option. N*N에 속할 때만
// 지뢰는 1개만 존재하는 것이 아닌 한 셀에 여러개가 존재할 수 있다. (1~9)
// 맵에 주어진 지뢰(개수)를 받아 실제 지뢰찾기 판을 만들어라
// condition. 지뢰는 *으로 개수는 숫자로 10개 이상이라면 M으로 나타냄

// 설계
// 보드 판은 Char 2차원 벡터로
// 각 숮자 입력은 그리디로 탐색
// ? 새로운 벡터를 만들어야 할까?

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, cnt;
    char c;
    cin >> n;
    vector<vector<char>> v(n, vector<char>(n));
    vector<vector<char>> resultVector(n, vector<char>(n));
    pair<int, int> dir[8] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}}; 

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> v[i][j];
        } 
    }

    int xPos, yPos;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){

            c = v[i][j];
            
            if (isdigit(c)){
                resultVector[i][j] = '*';
            }
            else{
                cnt = 0;
                for (int k = 0; k < 8; k++){
                    xPos = j + dir[k].first;
                    yPos = i + dir[k].second;
                    if ((xPos < 0 || xPos >= n) || (yPos < 0 || yPos >= n))
                        continue;

                    c = v[yPos][xPos];
                    if (isdigit(c)){
                        cnt += c - '0';
                    }
                }
                if (cnt >= 10)
                    resultVector[i][j] = 'M';
                else
                    resultVector[i][j] = '0' + cnt;
            }
        } 
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << resultVector[i][j];
        } 
        cout << '\n';
    }
}
