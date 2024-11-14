#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, bool flag) {
    return flag == true ? a + b : a - b;
}