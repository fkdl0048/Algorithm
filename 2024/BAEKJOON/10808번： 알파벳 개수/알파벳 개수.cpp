/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10808                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: fkdl4878 <boj.kr/u/fkdl4878>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10808                          #+#        #+#      #+#    */
/*   Solved: 2024/05/17 14:15:52 by fkdl4878      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>
using namespace std;

// int main(){
//     map<char, int> a;
//     string s;
//     cin >> s;

//     for (int i = 0; i < s.length(); i++)
//     {
//         a[s[i]]++;
//     }

//     for (char i = 'a'; i <= 'z'; i++)
//     {
//         cout << a[i] << ' ';
//     }
// }

int cnt[26];
int main(){
    string s;
    cin >> s;
    for (int i= 0; i < s.length(); i++)
    {
        cnt[s[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        cout << cnt[i] << ' ';
    }
}