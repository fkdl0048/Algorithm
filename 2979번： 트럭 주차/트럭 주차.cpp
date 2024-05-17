/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2979                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: fkdl4878 <boj.kr/u/fkdl4878>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2979                           #+#        #+#      #+#    */
/*   Solved: 2024/05/17 14:58:05 by fkdl4878      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>
using namespace std;

int cnt[104];
int main(){
    int a, b, c;
    int start, end;
    int ret = 0;

    cin >> a >> b >> c;
    
    for (int i = 0; i < 3; i++){
        cin >> start >> end;
        for (int j = start; j < end; j++){
            cnt[j]++;
        }
    }

    for (int i = 1; i < 100; i++){
        switch (cnt[i])
        {
        case 1:
            ret += a;
            break;
        case 2:
            ret += b * 2;
            break;
        case 3:
            ret += c * 3;
        default:
            break;
        }
    }
    
    cout << ret << '\n';
}