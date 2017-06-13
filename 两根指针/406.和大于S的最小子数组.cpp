class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @param s: an integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        // write your code here
        if(nums.empty())
            return -1;
        int len = nums.size();
        int left = 0, right = 0, sum = 0, res = len + 1;
        while(right < len)
        {
            while(sum < s && right < len)
            {
                sum = sum + nums[right];
                right++;
            }
            while(sum >= s)
            {
                res = min(res, right - left);
                sum = sum - nums[left];
                left++;
            }
        }
        return res == len + 1 ? -1 : res;
    }
};
