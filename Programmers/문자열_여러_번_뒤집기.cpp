#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
    for (const auto& pair : queries) {
        reverse(my_string.begin() + pair[0], my_string.begin() + pair[1] + 1);
    }
    
    return my_string;
}