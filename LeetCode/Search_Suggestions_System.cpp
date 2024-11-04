class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());

        vector<vector<string>> result;
        string prefix;

        for (char ch : searchWord) {
            prefix += ch;

            auto it = lower_bound(products.begin(), products.end(), prefix);

            vector<string> suggestions;

            for (int i = 0; i < 3 && it + i != products.end(); i++){
                if ((it + i)->substr(0, prefix.size()) == prefix) {
                    suggestions.push_back(*(it + i));
                } else {
                    break;
                }
            }

            result.push_back(suggestions);
        }

        return result;
    }
};