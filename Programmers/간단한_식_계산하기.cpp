#include <string>
#include <vector>

using namespace std;

int solution(string binomial) {
    int answer = 0;

    string num1 = "";
    int i = 0;
    while (i < binomial.length() && binomial[i] != ' ') {
        num1 += binomial[i];
        i++;
    }

    i += 3;

    string num2 = "";
    while (i < binomial.length()) {
        num2 += binomial[i];
        i++;
    }

    int a = stoi(num1);
    int b = stoi(num2);

    char op = binomial[num1.length() + 1];
    
    if (op == '+') {
        answer = a + b;
    }
    else if (op == '-') {
        answer = a - b;
    }
    else if (op == '*') {
        answer = a * b;
    }
    
    return answer;
}