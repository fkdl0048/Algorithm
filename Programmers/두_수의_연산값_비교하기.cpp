#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int sum1 = stoi(to_string(a) + to_string(b));
    int sum2 = 2 * a * b;
    
    return sum1 >= sum2 ? sum1 : sum2;
}