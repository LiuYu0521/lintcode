class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        // write your code here
        int len = nums.size();
        int min_sum = INT_MAX;
        int this_sum = 0;
        for(int i = 0; i < len; i++)
        {
            this_sum = this_sum + nums[i];
            if(this_sum < min_sum)
                min_sum = this_sum;
            if(this_sum > 0)
                this_sum = 0;
        }
        return min_sum;
    }
};
