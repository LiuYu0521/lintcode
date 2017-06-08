class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>& nums) {
        // write your code here
        int len = nums.size();
        int dp_min[len];
        int dp_max[len];
        int res = nums[0];
        dp_max[0] = nums[0];
        dp_min[0] = nums[0];
        for(int i = 1; i < len; i++)
        {
            dp_max[i] = max(nums[i], max(dp_min[i - 1] * nums[i], dp_max[i - 1] * nums[i]));
            dp_min[i] = min(nums[i], min(dp_min[i - 1] * nums[i], dp_max[i - 1] * nums[i]));
            res = max(res, dp_max[i]);
        }
        return res;
    }
};
