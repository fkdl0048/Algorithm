#include <string>
#include <vector>
#include <set>

using namespace std;

string solution(string my_string, vector<int> indices) {
    string answer = "";
    set<int> index_set(indices.begin(), indices.end());
    
    for (int i = 0; i < my_string.length(); i++) {
        if (index_set.find(i) == index_set.end()) {
            answer += my_string[i];
        }
    }
    
    return answer;
}