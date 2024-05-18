/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2559                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: fkdl4878 <boj.kr/u/fkdl4878>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2559                           #+#        #+#      #+#    */
/*   Solved: 2024/05/18 12:17:02 by fkdl4878      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int sum = 0, ans = 0;
    for (int i = 0; i < k; i++)
    {
        sum += v[i];
    }

    ans = sum;
    for (int i = k; i < n; i++)
    {
        sum += v[i] - v[i - k];
        ans = max(ans, sum);
    }

    cout << ans;
}