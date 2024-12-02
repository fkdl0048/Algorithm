#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    vector<string> strNumbers;
    
    for (int num : numbers) {
        strNumbers.push_back(to_string(num));
    }
    
    sort(strNumbers.begin(), strNumbers.end(), [](const string& a, const string& b) {
       return a + b > b + a; 
    });
    
    if (strNumbers[0] == "0") {
        return "0";
    }
    
    string result = "";
    for (const string& num : strNumbers) {
        result += num;
    }
    
    return result;
}