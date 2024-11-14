#include <vector>
using namespace std;

vector<int> solution(vector<int> arr) {
    int first_two = -1, last_two = -1;
    
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == 2) {
            if(first_two == -1) first_two = i;
            last_two = i;
        }
    }
    
    if(first_two == -1) return {-1};
    
    vector<int> result;
    for(int i = first_two; i <= last_two; i++) {
        result.push_back(arr[i]);
    }
    
    return result;
}