/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11659                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: fkdl4878 <boj.kr/u/fkdl4878>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11659                          #+#        #+#      #+#    */
/*   Solved: 2024/06/20 02:59:10 by fkdl4878      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

// 수 N개가 주어졌을 때, i~j까지의 합을 구하는 프로그램
// 투 포인터 문제이다.
// 개수 N과 합을 구해야 하는 횟수 M이 주어진다.
// 이후 M개의 줄에는 합을 구해야 하는 구간 i, j가 주어짐

// ps1
// 투 포인터 기법으로 고고

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // 입출력 속도 향상을 위한 코드
    cin.tie(NULL); // 입출력 속도 향상을 위한 코드

    int N, M;
    cin >> N >> M; // N: 배열의 크기, M: 합을 구해야 하는 구간의 개수

    vector<int> arr(N + 1, 0); // 배열 선언 및 초기화
    vector<int> prefix_sum(N + 1, 0); // 누적 합 배열 선언 및 초기화

    // 배열 입력
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
        prefix_sum[i] = prefix_sum[i - 1] + arr[i]; // 누적 합 계산
    }

    // 구간 합 구하기
    for (int i = 0; i < M; ++i) {
        int start, end;
        cin >> start >> end; // 구간의 시작과 끝 입력
        cout << prefix_sum[end] - prefix_sum[start - 1] << '\n'; // 구간 합 출력
    }
}