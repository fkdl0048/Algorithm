#include <string>
#include <vector>

using namespace std;

int solution(int number, int n, int m) {
    return ((number % n == 0) && (number % m == 0)) ? 1 : 0;
}