class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        // write your code here
        unordered_map<int, int> m;
        m[0] = -1;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum = sum + nums[i];
            if(m.find(sum) != m.end())
            {
                vector<int> res;
                res.push_back(m[sum] + 1);
                res.push_back(i);
                return res;
            }
            m[sum] = i;
        }
        vector<int> res;
        return res;
    }
};
