class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        int len = nums.size();
        int i = 0;
        int j = len - 1;
        while(i < j)
        {
            while(nums[i] % 2 == 1)
                i++;
            while(nums[j] % 2 == 0)
                j--;
            if(i < j)
            {
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
        }
    }
};
