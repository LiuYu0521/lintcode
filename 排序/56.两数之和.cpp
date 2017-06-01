class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        unordered_map<int, int> mp;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++)
        {
            if(mp.find(target - nums[i]) != mp.end())
            {
                result.push_back(mp[target - nums[i]]);
                result.push_back(i + 1);
                return result;
            }
            mp[nums[i]] = i + 1;
        }
    }
};
