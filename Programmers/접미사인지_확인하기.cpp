#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string my_string, string is_suffix) {
    
       if (is_suffix.length() > my_string.length()) {
        return 0;
    }

    string suffix = my_string.substr(my_string.length() - is_suffix.length());

    return (suffix == is_suffix) ? 1 : 0;
}