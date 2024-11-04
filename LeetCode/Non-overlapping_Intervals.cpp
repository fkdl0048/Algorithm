class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) 
        {
            return a[1] < b[1];
        });

        int result = 0;
        int index = 0;

        while (index < intervals.size()) {
            int end = intervals[index][1];
            index++;

            while (index < intervals.size() && intervals[index][0] < end) {
                index++;
                result++;
            }
        }

        return result;
    }
};