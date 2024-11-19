#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end());
    
    return max(numbers[0] * numbers[1], numbers[numbers.size() - 1] * numbers[numbers.size() - 2]);
}