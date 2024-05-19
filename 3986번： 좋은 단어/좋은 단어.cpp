/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 3986                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: fkdl4878 <boj.kr/u/fkdl4878>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/3986                           #+#        #+#      #+#    */
/*   Solved: 2024/05/19 17:11:00 by fkdl4878      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, cnt = 0;
    string s;

    cin >> n;

    while (n--){
        cin >> s;
        stack<char> st;

        for (char c : s){
            if (st.size() && st.top() == c) st.pop();
            else st.push(c);
        }

        if (st.size() == 0)
            cnt++;
    }

    cout << cnt;
}