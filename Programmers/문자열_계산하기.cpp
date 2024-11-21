#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string my_string) {
    stringstream ss(my_string);
    int result;
    ss >> result;
    
    char op;
    int number;
    
    while(ss >> op >> number) {
        if(op == '+') result += number;
        else if(op == '-') result -= number;
    }
    
    return result;
}