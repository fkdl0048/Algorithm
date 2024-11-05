#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    string answer = "";
    answer += my_string.substr(0, s);
    answer += overwrite_string;
    answer += my_string.substr(s + overwrite_string.length(), my_string.length());
    return answer;
}