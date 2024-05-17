#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> hash;
        vector<int> result;
        
        for (int i = 0; i < nums.size(); i++)
        {
            int numberToFind = target - nums[i];
            
            if (hash.find(numberToFind) != hash.end())
            {
                result.push_back(hash[numberToFind]);
                result.push_back(i);
                return result;
            }
            
            hash[nums[i]] = i;
        }
        
        return result;
    }
};

int main()
{
    Solution sol = Solution();
    vector<int> vec = {2, 7, 11, 15};
    vector<int> result = sol.twoSum(vec, 9);

    for (int i : result)
    {
        cout << i << ' ';
    }
}