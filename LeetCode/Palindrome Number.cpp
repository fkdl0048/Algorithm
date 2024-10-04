class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        
        int origin = x;
        long revers = 0;

        while (x > 0){
            revers = revers * 10 + (x % 10);
            x = x / 10;
        }

        return (revers == origin);
    }
};