/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1159                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: fkdl4878 <boj.kr/u/fkdl4878>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1159                           #+#        #+#      #+#    */
/*   Solved: 2024/05/18 00:28:46 by fkdl4878      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    map<char, int> cnt;
    string s, ret;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        cnt[s[0]]++;
    }

    for (auto it = cnt.begin(); it != cnt.end(); ++it)
    {
        if (it->second >= 5)
            ret += it->first;
    }

    cout << (ret.empty() ? "PREDAJA" : ret) << '\n';
}