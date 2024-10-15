/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1629                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: fkdl4878 <boj.kr/u/fkdl4878>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1629                           #+#        #+#      #+#    */
/*   Solved: 2024/05/19 17:29:57 by fkdl4878      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>
using namespace std;

long long mod_exp(long long a, long long b, long long c){
    if (b == 0) return 1;
    if (b == 1) return a % c;

    long long half = mod_exp(a, b / 2, c);
    long long result = (half * half) % c;

    if (b % 2 != 0){
        result = (result * a) % c;
    }

    return result;
}

int main(){
    long long a, b, c;

    cin >> a >> b >> c;
    cout << mod_exp(a, b, c) << '\n';

    return 0;
}