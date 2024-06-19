/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9012                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: fkdl4878 <boj.kr/u/fkdl4878>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9012                           #+#        #+#      #+#    */
/*   Solved: 2024/06/20 00:56:54 by fkdl4878      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

// 괄호 문자열 -> ()
// 올바른 괄호 문자열인지 판단.
// n이 주어지고 해당 문자열이 VPS(괄호 문자열)이라면
// YES 아니라면 NO

// ps1
// 스택문제로 알고 있음
// 스택에 넣어서 반대편 브라켓이 있을 때만 pop
// 스택이 비어있지 않다면 false
// 아니라면 true
// 위 로직을 함수로 만들어서 반복

// Q. 지금 문자열 넘겨주는거 복사 말고 전달 형식으로 해야하지 않을까?
// 값 참조로 넘기는게 좋다?

#include <bits/stdc++.h>

using namespace std;

bool isVPS(const string& s)
{
    stack<char> stack;

    for(const char c : s)
    {
        if (c == '(')
            stack.push('(');
        else
        {
            if (stack.empty())
                return false;
            stack.pop();
        }
    }

    return stack.empty();
}

int main()
{
    int n;
    string s;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (isVPS(s))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}