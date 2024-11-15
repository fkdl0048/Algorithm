#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> picture, int k) {
    vector<string> answer;
    
    for (int i = 0; i < picture.size(); i++) {
        string scaled_row = "";
        
        for (int j = 0; j < picture[i].length(); j++) {
            for (int idx = 0; idx < k; idx++) {
                scaled_row += picture[i][j];
            }
        }
        
        for (int y = 0; y < k; y++) {
            answer.push_back(scaled_row);
        }
    }
    
    return answer;
}