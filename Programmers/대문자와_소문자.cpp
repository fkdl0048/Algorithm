#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    for (char c : my_string) {
        if (islower(c)) {
            answer += c + ('A' - 'a');
        } else if (isupper(c)) {
            answer += c - ('A' - 'a');
        }
    }
                   
    return answer;
}