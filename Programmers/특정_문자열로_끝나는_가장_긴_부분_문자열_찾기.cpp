#include <string>
#include <vector>

using namespace std;

string solution(string myString, string pat) {
    int lastPos = myString.rfind(pat);
    
    return myString.substr(0, lastPos + pat.length());
}