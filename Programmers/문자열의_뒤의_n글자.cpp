#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n) {
    return my_string.substr(my_string.length() - n);
}