#include <string>
#include <vector>

using namespace std;

string solution(string rny_string) {
    int index = 0;
    while ((index = rny_string.find('m', index)) != string::npos) {
        rny_string.replace(index, 1, "rn");
        index += 2;
    }
    
    return rny_string;
}