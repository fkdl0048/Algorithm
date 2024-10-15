/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2309                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: fkdl4878 <boj.kr/u/fkdl4878>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2309                           #+#        #+#      #+#    */
/*   Solved: 2024/05/17 14:03:19 by fkdl4878      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <bits/stdc++.h>
using namespace std;

int a[9];
int main(){
    for (int i = 0; i < 9; i++)
    {
        cin >> a[i];
    }

    sort(a, a + 9);

    do{
        int sum = 0;
        for (int i = 0; i < 7; i++)
        {
            sum += a[i];
        }
        if (sum == 100) break;
    }
    while (next_permutation(a, a + 9));

    for (int i = 0; i < 7; i++)
    {
        cout << a[i] << '\n';
    }
}