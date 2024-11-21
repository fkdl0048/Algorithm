#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    return numbers[((k * 2) - 2) % numbers.size()];
}