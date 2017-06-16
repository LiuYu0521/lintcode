class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        int max_sum = INT_MIN;
        int this_sum = 0;
        int len = nums.size();
        for(int i = 0; i < len; i++)
        {
            this_sum = this_sum + nums[i];
            if(this_sum > max_sum)
                max_sum = this_sum;
            if(this_sum < 0)
                this_sum = 0;
        }
        return max_sum;
    }
};
