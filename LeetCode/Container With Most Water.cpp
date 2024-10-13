class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        while (left < right){
            int currentArea = min(height[left], height[right]) * (right - left);
            maxArea = max(maxArea, currentArea);
            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return maxArea;
    }
};

// 2회차 풀이


class Solution {
public:
    int maxArea(vector<int>& height) {
        int left =0;
        int right = height.size() - 1;
        int max = 0;
        int current = 0;

        while (left < right) {
            int wall = std::min(height[left], height[right]);
            current = wall * (right - left);
            
            if (current > max) {
                max = current;
            }

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max;
    }
};