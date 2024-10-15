/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9996                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: fkdl4878 <boj.kr/u/fkdl4878>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9996                           #+#        #+#      #+#    */
/*   Solved: 2024/05/18 03:06:49 by fkdl4878      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>
using namespace std;

int n;
string s, ori_s, pre, suf;
int main(){
    cin >> n;
    cin >> ori_s;

    int pos = ori_s.find('*');
    pre = ori_s.substr(0, pos);
    suf = ori_s.substr(pos + 1);
    for (int i = 0; i < n; i ++)
    {
        cin >> s;
        if (s.size() < pre.size() + suf.size())
            cout << "NE" << endl;
        else{
            if (pre == s.substr(0, pre.size()) && suf == s.substr(s.size() - suf.size()))
                cout << "DA" << endl;
            else
                cout << "NE" << endl;
        }
    }
}