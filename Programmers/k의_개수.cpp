#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;
    for (int idx = i; idx <= j; idx++) {
        for (char c : to_string(idx)) {
            if (c - '0' == k) {
                answer++;
            }
        }
    }
    
    return answer;
}