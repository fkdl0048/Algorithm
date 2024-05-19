/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1213                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: fkdl4878 <boj.kr/u/fkdl4878>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1213                           #+#        #+#      #+#    */
/*   Solved: 2024/05/19 15:54:03 by fkdl4878      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    map<char, int> m;

    cin >> s;

    for (char c : s){
        m[c]++;
    }

    int odd_cnt = 0;
    char odd_char;
    for (auto it : m){
        if (it.second % 2 != 0){
            odd_cnt++;
            odd_char = it.first;
        }
    }

    if (odd_cnt > 1){
        cout << "I'm Sorry Hansoo \n";
        return 0;
    }

    string half = "";
    for (auto it : m){
        half += string(it.second / 2, it.first);
    }

    sort(half.begin(), half.end());
    string palindrome = half;
    if (odd_cnt == 1){
        palindrome += odd_char;
    }

    reverse(half.begin(), half.end());
    palindrome += half;

    cout << palindrome;

    return 0;
}