#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> slicer, vector<int> num_list) {
    vector<int> answer;
    
    if (n == 1) {
        for (int i = 0; i <= slicer[1]; i++) {
            answer.push_back(num_list[i]);
        }
    } else if (n == 2) {
        for (int i = slicer[0]; i < num_list.size(); i++) {
            answer.push_back(num_list[i]);
        }
    } else if (n == 3) {
        for (int i = slicer[0]; i <= slicer[1]; i++) {
            answer.push_back(num_list[i]);
        }
    } else if (n == 4) {
        for (int i = slicer[0]; i <= slicer[1]; i += slicer[2]) {
            answer.push_back(num_list[i]);
        }
    }
    
    return answer;
}