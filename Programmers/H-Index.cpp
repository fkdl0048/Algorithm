#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());
    
    int h_index = 0;
    
    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] >= i + 1) {
            h_index = i + 1;
        }
        else {
            break;
        }
    }
    
    return h_index;
}