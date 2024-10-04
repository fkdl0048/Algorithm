#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<int> n = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> s = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string str;
        int i = 0;
        
        while(num > 0){
            if (num >= n[i]) {
                str += s[i];
                num -= n[i];
            } 
            else {
                i++;
            }
        }
        
        return str;
    }
};
