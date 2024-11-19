#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int num1, int num2) {
    double d = (double)num1 / num2;
    return (int)(d * 1000);
}