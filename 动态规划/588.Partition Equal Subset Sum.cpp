class Solution {
public:
    /**
     * @param nums a non-empty array only positive integers
     * @return return true if can partition or false
     */
    bool canPartition(vector<int>& nums) {
        // Write your code here
        int len = nums.size();
        int sum = 0;
        for(int i = 0;i < len; i++)
        {
            sum = sum + nums[i];
        }
        if(sum % 2 == 1)
            return false;
        sum = sum / 2;
        int dp[sum + 1];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < len; i++)
        {
            for(int j = sum; j > 0; j--)
            {
                if(j >= nums[i])
                {
                    dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
                }
            }
        }
        return dp[sum] == sum;
    }
};
