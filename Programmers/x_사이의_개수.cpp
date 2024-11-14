#include <string>
#include <vector>

using namespace std;

vector<int> solution(string myString) {
    vector<int> answer;
    int currentLength = 0;
    
    for (int i = 0; i < myString.length(); i++) {
        if (myString[i] == 'x') {
            answer.push_back(currentLength);
            currentLength = 0;
        } else {
            currentLength++;
        }
    }
    
    answer.push_back(currentLength);
    
    return answer;
}