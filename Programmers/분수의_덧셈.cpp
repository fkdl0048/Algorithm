#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    int numerator = numer1 * denom2 + numer2 * denom1;
    int denominator = denom1 * denom2;                

    int common = gcd(numerator, denominator);
    numerator /= common;
    denominator /= common;

    return {numerator, denominator};
}