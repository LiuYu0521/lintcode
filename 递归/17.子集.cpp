class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsets(vector<int> &nums) {
        // write your code here
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        vector<int> out;
        helper(0, nums, out, res);
        return res;
    }
    void helper(int k, vector<int> &nums, vector<int> &out, vector<vector<int>> &res)
    {
        if(k == nums.size())
        {
            res.push_back(out);
        }
        else
        {
            helper(k + 1, nums, out, res);
            out.push_back(nums[k]);
            helper(k + 1, nums, out, res);
            out.pop_back();
        }
    }
};
