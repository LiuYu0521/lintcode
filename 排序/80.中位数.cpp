class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int quickSort(vector<int> &nums, int left, int right)
    {
        int pivot = nums[left];
        int i = left + 1, j = right;
        while (i <= j)
        {
            while(i <= j && nums[j] > pivot)
                j--;
            while(i <= j && nums[i] < pivot)
                i++;
            if(i <= j)
            {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }
        swap(nums[left], nums[j]);
        return j;
    }
    int median(vector<int> &nums) {
        // write your code here
        int left = 0;
        int right = nums.size() - 1;
        int k = right / 2;
        while(true)
        {
            int pos = quickSort(nums, left, right);
            if(pos == k)
                return nums[k];
            else if(pos < k)
                left = pos + 1;
            else
                right = pos - 1;
        }
    }
};
