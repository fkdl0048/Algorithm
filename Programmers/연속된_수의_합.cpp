#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> result;

    // 첫 번째 수 계산
    int start = (total - (num * (num - 1) / 2)) / num;

    // 연속된 수를 계산하여 결과에 추가
    for (int i = 0; i < num; ++i) {
        result.push_back(start + i);
    }

    return result;
}