/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9375                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: fkdl4878 <boj.kr/u/fkdl4878>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9375                           #+#        #+#      #+#    */
/*   Solved: 2024/05/19 15:33:17 by fkdl4878      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int tcase;
    string a, b;
    int ret;
    
    cin >> tcase;
    while (tcase--)
    {
        map<string, int> m;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> a >> b;
            m[b]++;
        }

        ret = 1;
        for(auto it : m){
            ret *= it.second + 1;
        }

        cout << ret - 1 << '\n';
    }
}
