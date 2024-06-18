/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 4108                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: fkdl4878 <boj.kr/u/fkdl4878>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/4108                           #+#        #+#      #+#    */
/*   Solved: 2024/06/18 23:44:11 by fkdl4878      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

// RxC 개의 칸으로 이뤄진 지뢰판
// 8개의 인접한 칸을 표시한 채로 보드판을 반환하기
// idea 지뢰 발견 시 인전한 칸 숫자 1 증가

#include <bits/stdc++.h>

using namespace std;

pair<int, int> dir[8] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}}; 

vector<vector<char>> makeBoard(int r, int c){
    vector<vector<char>> v(r, vector<char>(c));

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin >> v[i][j];
        }
    }

    return v;
}

void changeBoard(vector<vector<char>> &v) {
    int rows = v.size();
    int cols = v[0].size();

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (v[i][j] == '.'){
                v[i][j] = '0';
            }
        }
    }

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (v[i][j] == '*'){
                for (int k = 0; k < 8; k++){
                    int nx = j + dir[k].first;
                    int ny = i + dir[k].second;

                    if (nx < 0 || nx >= cols || ny < 0 || ny >= rows)
                        continue;

                    if (v[ny][nx] != '*')
                        v[ny][nx]++;
                }
            }
        }
    }
}

void printBoard(vector<vector<char>> &v){
    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < v[i].size(); j++){
            cout << v[i][j];
        }
        cout << '\n';
    }
}

int main(){
    int R, C;

    while (1){
        cin >> R >> C;

        if((R == 0) && (C == 0))
            break;

        auto v = makeBoard(R, C);
        changeBoard(v);
        printBoard(v);
    }
}