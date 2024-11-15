#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> str_list) {
    for (int i = 0; i < str_list.size(); i++) {
        if (str_list[i] == "l") {
            return vector(str_list.begin(), str_list.begin() + i);
        } else if (str_list[i] == "r") {
            return vector(str_list.begin() + i + 1, str_list.end());
        }
    }
                   
    return {};
}