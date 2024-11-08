#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    
    for (int i = 0; i < pat.length(); i++) {
        if (pat[i] == 'A') {
            pat[i]++;
        } else {
            pat[i]--;
        }
    }
    
    if (myString.find(pat) != string::npos) {
        return 1;
    }
    return 0;
}