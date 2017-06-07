class Solution {
public:
    /**
     * @param nums a set of distinct positive integers
     * @return the largest subset
     */
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // Write your code here
        sort(nums.begin(), nums.end());

        vector<int> dp(nums.size(), 0);
        vector<int> father(nums.size(), 0);

        int n = nums.size();
        int m = 0;
        int index = -1;

        for(int i = 0; i < n; ++i) {
            father[i] = -1;
            dp[i] = 1;

            for(int j = 0; j < i; ++j) {
                if(nums[i] % nums[j] == 0 && dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                    father[i] = j;
                }
            }

            if(dp[i] >= m) {
                m = dp[i];
                index = i;
            }
        }

        vector<int> result;
        for(int i = 0; i < m; ++i) {
            result.push_back(nums[index]);
            index = father[index];
        }
        return result;
    }
};
