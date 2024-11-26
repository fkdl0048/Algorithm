#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int diff = common[1] - common[0];
    if (common[2] - common[1] == diff) {
        return common.back() + diff;
    } else {
        int ratio = common[1] / common[0];
        return common.back() * ratio;
    }
}