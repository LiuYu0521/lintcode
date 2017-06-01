class Solution {
public:
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        // write your code here
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            int target = -nums[i];
            int start = i + 1;
            int end = nums.size() - 1;
            while(start < end)
            {
                if(start > i + 1 && nums[start] == nums[start - 1])
                {
                    start++;
                    continue;
                }
                if(nums[start] + nums[end] == target)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[start]);
                    temp.push_back(nums[end]);
                    result.push_back(temp);
                    start++;
                    end--;
                }
                else if(nums[start] + nums[end] < target)
                    start++;
                else
                    end--;
            }
        }
        return result;
    }
};
