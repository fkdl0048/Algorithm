using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> m;
        int n = grid.size();
        int result = 0;

        for (auto& row : grid) {
            m[row]++;
        }

        for (int col = 0; col < n; col++) {
            vector<int> temp;
            for (int row = 0; row < n; row++) {
                temp.push_back(grid[row][col]);
            }

            result += m[temp];
        }

        return result;
    }
};
