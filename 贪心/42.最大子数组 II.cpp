class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        // write your code here
        int len = nums.size();
        if(len == 0)
        {
            return 0;
        }
        int left[len], right[len];
        int sum = 0, max_sum = INT_MIN;
        for(int i = 0; i < len; i++)
        {
            sum = sum + nums[i];
            max_sum = max(max_sum, sum);
            sum = max(sum, 0);
            left[i] = max_sum;
        }
        sum = 0;
        max_sum = INT_MIN;
        for(int i = len - 1; i >= 0; i--)
        {
            sum = sum + nums[i];
            max_sum = max(max_sum, sum);
            sum = max(sum, 0);
            right[i] = max_sum;
        }
        max_sum = INT_MIN;
        for(int i = 0; i < len - 1; i++)
        {
            max_sum = max(max_sum, left[i] + right[i + 1]);
        }
        return max_sum;
    }
};
