#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int num1 = stoi(to_string(a) + to_string(b));
    int num2 = stoi(to_string(b) + to_string(a));
    
    return num1 >= num2 ? num1 : num2;
}