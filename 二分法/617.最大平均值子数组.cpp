class Solution {
public:
    /**
     * @param nums an array with positive and negative numbers
     * @param k an integer
     * @return the maximum average
     */
    double maxAverage(vector<int>& nums, int k) {
        // Write your code here
        double left = INT_MAX, right = INT_MIN;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(nums[i] < left)
                left = nums[i];
            if(nums[i] > right)
                right = nums[i];
        }
        double sum[1000000] = {0};
        sum[0] = 0;
        while(right - left >= 1e-6)
        {
            double mid = (left + right) / 2.0;
            double min_pre = 0;
            bool check = false;
            for(int i = 1; i <= n; i++)
            {
                sum[i] = sum[i - 1] + nums[i - 1] - mid;
                if(i >= k && sum[i] - min_pre >= 0)
                {
                    check = true;
                    break;
                }
                if(i >= k)
                {
                    min_pre = min(min_pre, sum[i - k + 1]);
                }
            }
            if(check)
                left = mid;
            else
                right = mid;
        }
        return left;
    }
};
