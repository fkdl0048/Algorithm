#include <string>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const vector<string> validWords = {"aya", "ye", "woo", "ma"};

bool canPronounce(string word) {
    for (const auto& valid : validWords) {
        size_t pos;
        while ((pos = word.find(valid)) != string::npos) {
            word.replace(pos, valid.length(), " ");
        }
    }
    word.erase(remove(word.begin(), word.end(), ' '), word.end());
    return word.empty();
}

int solution(vector<string> babbling) {
    int count = 0;
    for (const auto& word : babbling) {
        if (canPronounce(word)) {
            count++;
        }
    }
    return count;
}