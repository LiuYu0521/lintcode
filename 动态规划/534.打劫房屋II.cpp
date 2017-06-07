class Solution {
public:
    /**
     * @param nums: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    int houseRobber2(vector<int>& nums) {
        // write your code here
        int len = nums.size();
        if(len == 0)
            return 0;
        if(len == 1)
            return nums[0];
        vector<int> nums1 = nums;
        vector<int> nums2 = nums;
        nums1.pop_back();
        nums2.erase(nums2.begin());
        return max(houseRobber(nums1), houseRobber(nums2));
    }
    int houseRobber(vector<int> A) {
        // write your code here
        int len = A.size();
        if(len == 0)
            return 0;
        if(len == 1)
            return A[0];
        int dp[len + 1];
        dp[0] = 0;
        dp[1] = A[0];
        for(int i = 2; i <= len; i++)
        {
            dp[i] = max(A[i - 1] + dp[i - 2], dp[i - 1]);
        }
        return dp[len];
    }
};
