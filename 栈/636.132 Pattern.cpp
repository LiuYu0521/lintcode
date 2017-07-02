class Solution {
public:
    /**
     * @param nums a list of n integers
     * @return true if there is a 132 pattern or false
     */
    bool find132pattern(vector<int>& nums) {
        // Write your code here
        int third = INT_MIN;
        stack<int> s;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            if(nums[i] < third)
                return true;
            else
            {
                while(!s.empty() && nums[i] > s.top())
                {
                    third = s.top();
                    s.pop();
                }
            }
            s.push(nums[i]);
        }
        return false;
    }
};
