#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer;
    string temp = "";
    int pos = 0;
    
    while (pos < my_str.length()) {
        temp = my_str.substr(pos, n);
        answer.push_back(temp);
        pos += n;
    }
    
    return answer;
}