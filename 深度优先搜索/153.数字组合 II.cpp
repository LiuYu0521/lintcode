class Solution {
public:
    /**
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // write your code here
        vector<vector<int>> res;
        sort(num.begin(), num.end());
        vector<int> out;
        helper(num, target, 0, out, res);
        return res;
    }
    void helper(vector<int> &num, int target, int start, vector<int> out, vector<vector<int>> &res)
    {
        if(target < 0)
            return;
        else if(target == 0)
            res.push_back(out);
        else
        {
            for(int i = start; i < num.size(); i++)
            {
                if(i > start && num[i] == num[i - 1])
                    continue;
                out.push_back(num[i]);
                helper(num, target - num[i], i + 1, out, res);
                out.pop_back();
            }
        }
    }
};
