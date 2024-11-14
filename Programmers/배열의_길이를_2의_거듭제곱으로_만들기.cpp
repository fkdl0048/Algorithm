#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) {
    int len = arr.size();
    int power = 1;
    
    while (power < len) {
        power *= 2;
    }
    
    arr.resize(power, 0);
    
    return arr;
}