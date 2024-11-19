#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string letter) {
    int pos = 0;
    while ((pos = my_string.find(letter)) != string::npos) 
        my_string.erase(pos, letter.length());
    return my_string;
}