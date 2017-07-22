class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: return nothing (void), do not return anything, modify nums in-place instead
     */
    void nextPermutation(vector<int> &nums) {
        // write your code here
        int i, j, n = nums.size();
        for(i = n - 2; i >= 0; i--)
        {
            if(nums[i + 1] > nums[i])
            {
                for(j = n - 1; j >= i; j--)
                {
                    if(nums[j] > nums[i])
                        break;
                }
                swap(nums[i], nums[j]);
                reverse(nums.begin() + i + 1, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
    }
};
