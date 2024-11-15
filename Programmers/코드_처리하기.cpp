#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    string ret = "";
    int mode = 0;
    
    for(int idx = 0; idx < code.length(); idx++) {
        if(code[idx] == '1') {
            mode = !mode; 
            continue;
        }
        
        if((mode == 0 && idx % 2 == 0) || 
           (mode == 1 && idx % 2 == 1)) {
            ret += code[idx];
        }
    }
    
    return ret.empty() ? "EMPTY" : ret;
}