class Solution {
public:
    /**
     * @param nums a list of integer
     * @return void
     */
    void wiggleSort(vector<int>& nums) {
        // Write your code here
        vector<int> temp = nums;
        int n = nums.size();
        sort(temp.begin(), temp.end());
        int i = (n - 1) / 2;
        int j = n - 1;
        for(int k = 0; k < n; k++)
        {
            if(k % 2 == 0)
            {
                nums[k] = temp[i];
                i--;
            }
            else
            {
                nums[k] = temp[j];
                j--;
            }
        }
    }
};
