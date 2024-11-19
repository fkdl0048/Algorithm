#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
    string numstr = to_string(num);
    
    for (int i = 0; i < numstr.length(); i++) {
        if (numstr[i] == k + '0') {
            return i + 1;
        }
    }
    
    return -1;
}