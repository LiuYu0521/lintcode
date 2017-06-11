class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        // write your code here
        int len = heights.size();
        if(len == 0 || len == 1)
            return 0;
        int left = 0;
        int right = len - 1;
        int res = 0;
        while(left <= right)
        {
            res = max(res, (right - left) * min(heights[left], heights[right]));
            if(heights[left] < heights[right])
                left++;
            else
                right--;
        }
        return res;
    }
};
