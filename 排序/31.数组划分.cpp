class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        int i = 0;
        int j = nums.size() - 1;
        while(i <= j)
        {
            while(i <= j && nums[i] < k)
                i++;
            while(i <= j && nums[j] >= k)
                j--;
            if(i <= j)
            {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }
        return i;
    }
};
