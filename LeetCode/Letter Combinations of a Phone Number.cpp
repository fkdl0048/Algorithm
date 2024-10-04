using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {

        if (digits.empty()) return {};
        
        unordered_map<char, string> map = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}       
        };

        vector<string> result;
        string current;
        backtrack(digits, 0, current, map, result);
        return result;
    }

private:
    void backtrack(const string& digits, int index, string& current, unordered_map<char, string>& map, vector<string>& result){

        if (index == digits.length()){
            result.push_back(current);
            return;
        }

        char digit = digits[index];
        string letters = map[digit];
        for (char letter : letters){
            current.push_back(letter);
            backtrack(digits, index + 1, current, map, result);
            current.pop_back();
        }
    }
};