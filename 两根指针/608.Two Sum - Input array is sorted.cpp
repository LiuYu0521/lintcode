class Solution {
public:
    /*
     * @param nums an array of Integer
     * @param target = nums[index1] + nums[index2]
     * @return [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        int len = nums.size();
        int i = 0;
        int j = len - 1;
        vector<int> res;
        while(true)
        {
            if(nums[i] + nums[j] == target)
                break;
            else if(nums[i] + nums[j] < target)
                i++;
            else
                j--;
        }
        res.push_back(i + 1);
        res.push_back(j + 1);
        return res;
    }
};
