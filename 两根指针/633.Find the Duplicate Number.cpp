class Solution {
public:
    /**
     * @param nums an array containing n + 1 integers which is between 1 and n
     * @return the duplicate one
     */
    int findDuplicate(vector<int>& nums) {
        // Write your code here
        int slow = 0, fast = 0, t = 0;
        while(true)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast)
                break;
        }
        while(true)
        {
            slow = nums[slow];
            t = nums[t];
            if(slow == t)
                break;
        }
        return slow;
    }
};
