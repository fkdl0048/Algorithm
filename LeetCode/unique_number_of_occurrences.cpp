class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> countMap;
        unordered_set<int> occurrenceSet; 

        for (int num : arr) {
            countMap[num]++;
        }

        for (auto& pair : countMap) {
            if (occurrenceSet.find(pair.second) != occurrenceSet.end()) {
                return false;
            }

            occurrenceSet.insert(pair.second);
        }

        return true;
    }
};
