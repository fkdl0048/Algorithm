#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    
    for (int i = 0; i < myString.length(); i++) {
        myString[i] = tolower(myString[i]);
    }
    
    for (int i = 0; i < pat.length(); i++) {
        pat[i] = tolower(pat[i]);
    }
    
    return myString.find(pat) != string::npos ? 1 : 0;
}