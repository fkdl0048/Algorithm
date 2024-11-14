#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    vector<int> diff;
    int answer = 0;
    
    while (true) {
        diff = arr;
        
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > 50 && arr[i] % 2 == 0) {
                arr[i] = arr[i] / 2;
            } else if (arr[i] < 50 && arr[i] % 2 != 0) {
                arr[i] = arr[i] * 2 + 1;
            }
        }
        
        if (arr == diff) {
            return answer;
        }
        
        answer++;
    }
    
    
    return answer;
}