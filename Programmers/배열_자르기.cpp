#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, int num1, int num2) {
    vector<int> answer(numbers.begin() + num1, numbers.begin() + num2 + 1);
    return answer;
}