class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        if(nums.size() <= 2)
            return nums.size();
        int len = nums.size();
        int left = 1;
        int right = 2;
        while(right < len)
        {
            if(nums[left] == nums[right] && nums[right] == nums[left - 1])
                right++;
            else
            {
                left++;
                nums[left] = nums[right];
                right++;
            }
        }
        return left + 1;
    }
};
