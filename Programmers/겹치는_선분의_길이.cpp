#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> lines) {
    vector<int> overlap(201, 0);

    for (const auto& line : lines) {
        int start = line[0] + 100;
        int end = line[1] + 100;
        for (int i = start; i < end; ++i) {
            overlap[i]++;
        }
    }

    int result = 0;
    for (int i = 0; i < 201; ++i) {
        if (overlap[i] > 1) {
            result++;
        }
    }

    return result;
}