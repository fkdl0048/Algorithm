/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11650                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: fkdl4878 <boj.kr/u/fkdl4878>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11650                          #+#        #+#      #+#    */
/*   Solved: 2024/06/18 21:38:18 by fkdl4878      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int p1, p2;
    vector<pair<int, int>> s;

    for (int i = 0; i < n; i++)
    {
        cin >> p1 >> p2;
        s.push_back(make_pair(p1, p2));
    }

    sort(s.begin(), s.end());

    for(auto p : s)
    {
        cout << p.first << " " << p.second << '\n';
    }
}