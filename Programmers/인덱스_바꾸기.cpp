#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string my_string, int num1, int num2) {
    swap(my_string[num1], my_string[num2]);
    return my_string;
}