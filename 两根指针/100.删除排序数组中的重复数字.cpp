class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        if(nums.size() == 0 || nums.size() == 1)
            return nums.size();
        int len = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[len] != nums[i])
            {
                len++;
                nums[len] = nums[i];
            }
        }
        return len + 1;
    }
};
