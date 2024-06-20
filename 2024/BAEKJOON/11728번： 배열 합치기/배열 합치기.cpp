/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11728                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: fkdl4878 <boj.kr/u/fkdl4878>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11728                          #+#        #+#      #+#    */
/*   Solved: 2024/06/20 05:28:45 by fkdl4878      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

// 배열을 합치는 문제이지만, 그대로 하면 시간초과

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    int aIndex = 0, bIndex = 0;

    cin >> n >> m;
    int a[n + 1], b[m + 1];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    while (aIndex < n || bIndex < m)
    {
        if (a[aIndex] <= b[bIndex])
            cout << a[aIndex++] << ' ';
        else
            cout << b[bIndex++] << ' ';
    }

    while (aIndex < n )
        cout << a[aIndex++] << ' ';
    while (bIndex < m )
        cout << b[bIndex++] << ' ';
}