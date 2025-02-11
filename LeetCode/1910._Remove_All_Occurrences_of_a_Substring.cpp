class Solution {
public:
    string removeOccurrences(string s, string part) {
        size_t pos;
        
        while ((pos = s.find(part)) != string::npos) {
            std::cout << pos;
            s.erase(pos, part.length());
        }

        return s;        
    }
};