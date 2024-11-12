#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_prefix) {
    return my_string.substr(0, is_prefix.length()) == is_prefix ? 1 : 0;
}