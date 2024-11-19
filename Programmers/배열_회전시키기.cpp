#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
    if (direction == "right") {
        rotate(numbers.rbegin(), numbers.rbegin() + 1, numbers.rend());
    } else {
        rotate(numbers.begin(), numbers.begin() + 1, numbers.end());
    }
    
    return numbers;
}