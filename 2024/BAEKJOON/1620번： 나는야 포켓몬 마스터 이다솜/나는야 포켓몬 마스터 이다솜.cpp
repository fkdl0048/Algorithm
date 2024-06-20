/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1620                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: fkdl4878 <boj.kr/u/fkdl4878>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1620                           #+#        #+#      #+#    */
/*   Solved: 2024/05/18 12:52:46 by fkdl4878      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    string s;
    map <string, int> m1;
    map <int, string> m2;

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> s;
        m1[s] = i;
        m2[i] = s;
    }

    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        if (isdigit(s[0]))
        {
            cout << m2[stoi(s)] << '\n';
        }
        else
        {
            cout << m1[s] << '\n';
        }
    }
}