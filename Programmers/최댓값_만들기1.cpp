#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    sort(numbers.rbegin(), numbers.rend());
    return numbers[0] * numbers[1];
}