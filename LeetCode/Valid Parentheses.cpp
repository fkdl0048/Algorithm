using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> bucket;

        for (char c : s){
            if (c == '(' || c == '{' || c == '['){
                bucket.push(c);
            }
            else {
                if (bucket.empty() || !isParentheses(bucket.top(), c)) {
                    return false;
                }
                bucket.pop();
            }
        }

        return bucket.empty();
    }
private:
    bool isParentheses(char left, char right){
        if (left == '(' && right == ')')
            return true;
        if (left == '{' && right == '}')
            return true;
        if (left == '[' && right == ']')
            return true;
        return false;
    }
};