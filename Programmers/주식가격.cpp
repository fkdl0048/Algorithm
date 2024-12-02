#include <string>
#include <vector>

using namespace std;

std::vector<int> solution(std::vector<int> prices) {
    int size = prices.size();
    std::vector<int> answer(size);
    
    for(int i = 0; i < size; i++) {
        int duration = 0;
        
        for(int j = i + 1; j < size; j++) {
            duration++;
            if(prices[i] > prices[j]) break;
        }
        
        answer[i] = duration;
    }
    
    return answer;
}