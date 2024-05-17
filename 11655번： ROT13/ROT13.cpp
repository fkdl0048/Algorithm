/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11655                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: fkdl4878 <boj.kr/u/fkdl4878>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11655                          #+#        #+#      #+#    */
/*   Solved: 2024/05/18 02:37:46 by fkdl4878      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin, s);

    for (int i = 0; i < s.length(); i++)
    {
        if (isalpha(s[i]))
        {
            if (islower(s[i]))
                s[i] = (s[i] - 'a' + 13) % 26 + 'a'; 
            else
                s[i] = (s[i] - 'A' + 13) % 26 + 'A';
        }
    }

    cout << s << endl;
}
