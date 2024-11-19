#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> array, int height) {
    sort(array.begin(), array.end());
    
    for (int i = 0; i < array.size(); i++) {
        if (array[i] > height) {
            return array.size() - i;
        }
    }
    
    return 0;
}