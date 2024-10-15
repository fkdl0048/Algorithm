/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1920                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: fkdl4878 <boj.kr/u/fkdl4878>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1920                           #+#        #+#      #+#    */
/*   Solved: 2024/06/20 02:32:45 by fkdl4878      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

// N개의 정수가 주어질 때, 이 안에 X라는 정수가 존재하는지 알아내는 것
// N이 주어지고 N개의 정수를 입력 받는다.
// 다음 줄에 M이 주어지고, M개의 수들이 주어지는데,
// 이 수들이 N으로 만들어진 배열에 존재하는지 판단
// 있다면 1 없다면 0
// 즉, N배열에서 M배열에 존재하는 값 마다 한번씩

// ps1
// 이분탐색 문제이니, M마다 각각 N의 배열에서 이분 탐색을 진행..
// 정렬되어 있다는 기준 하에 진행
// 

#include <bits/stdc++.h>

using namespace std;

int serach(const vector<int> &v, int find)
{
    int left = 0;
    int right = v.size() - 1;
    
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (v[mid] == find)
            return 1;
        else if (v[mid] < find)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return 0;
}

int main()
{
    int n, m, temp;
    vector<int> v;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end());

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        cout << serach(v ,temp) << '\n';
        // cout << binary_search(v.begin(), v.end(), temp);
    }
}