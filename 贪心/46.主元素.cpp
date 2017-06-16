class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int len = nums.size();
        int count = 0;
        int res;
        for(int i = 0; i < len; i++)
        {
            if(count == 0)
            {
                res = nums[i];
                count++;
            }
            else
            {
                if(res == nums[i])
                {
                    count++;
                }
                else
                {
                    count--;
                }
            }
        }
        return res;
    }
};
