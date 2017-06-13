class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        // write your code here
        int left = 0, right = heights.size() - 1, res = 0;
        while(left < right)
        {
            int small = min(heights[left], heights[right]);
            if(small == heights[left])
            {
                left++;
                while(left < right && heights[left] < small)
                {
                    res = res + (small - heights[left]);
                    left++;
                }
            }
            else
            {
                right--;
                while(left < right && heights[right] < small)
                {
                    res = res + (small - heights[right]);
                    right--;
                }
            }
        }
        return res;
    }
};
