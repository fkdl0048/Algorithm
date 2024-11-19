#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string my_string) {
    string answer = "";
    for (int i = 0; i < my_string.length(); i++) {
        if (isupper(my_string[i])) {
            my_string[i] -= 'A' - 'a';
        }
    }
    
    sort(my_string.begin(), my_string.end());

    return my_string;
}