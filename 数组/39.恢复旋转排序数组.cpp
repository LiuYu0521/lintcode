class Solution {
public:
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        int len = nums.size();
        int index = 0;
        for(; index < len - 1; index++)
        {
            if(nums[index] > nums[index + 1])
                break;
        }
        if(index == len - 1)
            return;
        sort(nums.begin(), nums.begin() + index);
        sort(nums.begin() + index + 1, nums.end());
        sort(nums.begin(), nums.end());
    }
};
