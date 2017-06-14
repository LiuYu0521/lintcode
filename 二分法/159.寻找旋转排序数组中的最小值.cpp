class Solution {
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) {
        // write your code here
        int left = 0, right = nums.size() - 1;
        if(nums[left] > nums[right])
        {
            while(left + 1 != right)
            {
                int mid = (left + right) / 2;
                if(nums[left] < nums[mid])
                    left = mid;
                else
                    right = mid;
            }
            return min(nums[left], nums[right]);
        }
        return nums[0];
    }
};
