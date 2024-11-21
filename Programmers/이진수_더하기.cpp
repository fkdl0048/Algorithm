#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string bin1, string bin2) {
    string result = "";
    int carry = 0;
    int i = bin1.length() - 1;
    int j = bin2.length() - 1;

    while(i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if(i >= 0) sum += bin1[i--] - '0';
        if(j >= 0) sum += bin2[j--] - '0';
        
        result += to_string(sum % 2);
        carry = sum / 2;
    }

    reverse(result.begin(), result.end());
    return result;
}