#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int oddNum = 0;
    int evenNum = 0;
    
    for (int n : num_list) {
        if (n % 2 == 0) {
            evenNum = evenNum * 10 + n;
        } else {
            oddNum = oddNum * 10 + n;
        }
    }
    
    return oddNum + evenNum;
}