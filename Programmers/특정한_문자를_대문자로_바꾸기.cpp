#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string alp) {
    int index = 0;
    
    while ((index = my_string.find(alp, index)) != string::npos) {
        my_string[index] = toupper(my_string[index]);
    }
    
    return my_string;
}