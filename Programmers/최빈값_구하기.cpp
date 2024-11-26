#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> array) {
    unordered_map<int, int> freq_map;

    for (int num : array) {
        freq_map[num]++;
    }

    int max_freq = 0;        
    int mode = -1;           
    bool is_unique = true;

    for (const auto& pair : freq_map) {
        if (pair.second > max_freq) {
            max_freq = pair.second;
            mode = pair.first;
            is_unique = true;
        } else if (pair.second == max_freq) {
            is_unique = false;
        }
    }

    return is_unique ? mode : -1;
}