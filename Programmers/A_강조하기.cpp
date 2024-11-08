#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    string answer = "";
    
for (int i = 0; i < myString.length(); i++) {
        if (myString[i] == 'a' || myString[i] == 'A') {
            answer += 'A';
        } else if (isupper(myString[i])) {
            answer += tolower(myString[i]);
        } else {
            answer += myString[i]; 
        }
    }
    return answer;
}