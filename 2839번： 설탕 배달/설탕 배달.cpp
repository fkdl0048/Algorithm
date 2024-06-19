/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2839                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: fkdl4878 <boj.kr/u/fkdl4878>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2839                           #+#        #+#      #+#    */
/*   Solved: 2024/06/19 22:56:29 by fkdl4878      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

// 3kg, 5kg 봉지가 있다.
// 18kg 킬로그램 -> 3kg 6개 but 5kg 3개 3kg 1개면 더 적은 봉지
// 배달하는 봉지의 최소 개수를 출력
// Option 정확하게 출력 불가능 하다면 -1 출력

// 1. 가장 먼저 효율적으로 5로 나누고 나머지가 3으로 나눠 떨어지는지 검사.
// (적은 봉지를 써야 하기에)
// 2. 불가능 하다면 3으로 나눠서 몫을 출력
// 3. 이것도 불가능 하다면 -1 반환

// 반례
// 11의 경우 5 3 3 으로 3개가 나와야 하지만 위의 로직으론 도출 불가능
// 무식하게 푼 경우에서 벗어나야 함

// ps 1
// 현재 n를 5와 3으로 나눠지는지 확인 (n % 5 and n % 3)
// 재귀로 풀어야 할 것 같은 느낌... 스택?
// 5로 나눠진다면 기존 값을 스택에 담고 진행
// 이후 나눠 떨어지지 않는다면 기존 값을 팝해서 검사.. 우선순위는 %5
// 스택이 비었다면 종료

#include <bits/stdc++.h>

using namespace std;

int packageSugerPS1(int n)
{
    int cnt = 0;
    stack<int> s;
    s.push(n);

    int cur = s.top();

    while(1)
    {
        if ((cur - 5) >= 0)
        {
            s.push(cur - 5);
            cnt++;
        }
        else if ((cur - 3) >= 0)
        {
            s.push(cur - 3);
            cnt++;
        }
        else 
        {

        }
    }



    return -1;
}

int packageSuger(int n)
{

    int temp = n;
    int cnt = 0;

// 1.
    while(1)
    {
        if (temp < 0)
        {
            temp = n;
            cnt = 0;
            break;
        }
        if (temp == 0)
        {
            return cnt;
        }
        if (temp == 3)
        {
            return cnt++;
        }
            
        temp = temp - 5;
        cnt++;
    }
    
// 2.
    while (1)
    {
        if (temp < 0)
        {
            break;
        }
        if (temp == 0)
        {
            return cnt;
        }
        temp = temp - 3;
        cnt++;
    }
    
// 3.
    return -1;
}

int main(){

    int n;

    cin >> n;

    cout << packageSugerPS1(n);
}

// 그리디 풀이

#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int result = -1;
    for (int i = N / 5; i >= 0; i--) {
        int remainder = N - (i * 5);
        if (remainder % 3 == 0) {
            result = i + (remainder / 3);
            break;
        }
    }
    
    cout << result << endl;
    return 0;
}

// 정답 코드 흐름
// 1. 처음 5로 나눈 몫을 가지고 줄여가면서 계산
// 2. 현재 5의 최대 몫으로 나눈 나머지가 3으로 나눴을 때 나머지가 0이라면
// 즉, 0도 포함..
// 3. 3으로 나누고 해당 몫을 더해서 값을 반환
// 4. 이 과정을 5의 몫을 하나씩 줄여가면서 계산

// dp 풀이
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    // DP 테이블 초기화
    vector<int> dp(N + 1, 5000); // 큰 값으로 초기화 (5000은 충분히 큰 값)
    dp[0] = 0; // 0kg는 0개의 봉지로 가능

    // DP 수행
    for (int i = 3; i <= N; i++) {
        if (i >= 3) dp[i] = min(dp[i], dp[i - 3] + 1);
        if (i >= 5) dp[i] = min(dp[i], dp[i - 5] + 1);
    }

    // 결과 출력
    if (dp[N] == 5000) cout << -1 << endl;
    else cout << dp[N] << endl;

    return 0;
}

// dp 복습
// 가장 먼저 계산 결과를 저장할, 최적의 해를 찾는 문제이기 때문에
// 5000의 큰 값으로 초기화
// dp[0]부터 바텀 업으로 