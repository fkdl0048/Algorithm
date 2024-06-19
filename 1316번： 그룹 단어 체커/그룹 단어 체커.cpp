/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1316                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: fkdl4878 <boj.kr/u/fkdl4878>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1316                           #+#        #+#      #+#    */
/*   Solved: 2024/06/19 23:39:41 by fkdl4878      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

// 그룹단어 <- 문자가 연속해서 나오는 경우
// ex ccazzzzbb -> c a z b 가 연속해서 나옴
// but aabbbccb는 b가 떨어져서 나오기에 그룹 단어가 아님
// 단어 N개를 입력받아 그룹단어의 개수를 출력

// ps1
// 해쉬 맵을 사용해서 해당 알파벳개수를 증가시킴
// 만약 알파벳이 바뀌면 해당 벨류 값을 -1로 초기화
// -1에 다시 방문하면 false 문제가 없다면 true

#include <bits/stdc++.h>

using namespace std;

bool groupWordCheck(string s)
{
    char prev;
    unordered_map<char, int> m;

    prev = s[0];
    for(char c : s)
    {
        if (m[c] == -1)
        {
            return false;
        }
        if (m[c] != prev)
        {
            m[prev] = -1;
        }
        prev = c;
        m[c]++;
    }

    return true;
}

int main()
{
    int n, cnt = 0; 
    string s;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (groupWordCheck(s)) cnt++;
    }
    
    cout << cnt;
}