#include <string>
#include <vector>

using namespace std;

int solution(int num, int n) {
    return num % n == 0 ? 1 : 0;
}