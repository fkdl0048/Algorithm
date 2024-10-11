class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();

        for (int i = 0; i < size; i++) {
            if (flowerbed[i] == 0) {
                int left = i - 1;
                int right = i + 1;

                if (left < 0) {
                    left = i;
                }
                if (right >= size) {
                    right = i;
                }

                if (flowerbed[left] == 0 && flowerbed[right] == 0) {
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }

        return n <= 0;
    }
};