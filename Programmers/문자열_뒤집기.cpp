#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, int s, int e) {
    reverse(my_string.begin() + s, my_string.begin() + e + 1);
    
    return my_string;
}