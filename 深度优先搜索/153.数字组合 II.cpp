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
        int len = num.size();
        if(len == 0)
            return res;
        sort(num.begin(), num.end());
        vector<int> out;
        int sum = 0;
        helper(0, sum, target, out, num, res);
        return res;
    }
    void helper(int k, int sum, int &target, vector<int> out, vector<int> &num, vector<vector<int>> &res)
    {
        if(k == num.size())
        {
            return;
        }
        else
        {
            helper(k + 1, sum, target, out, num, res);
            sum = sum + num[k];
            out.push_back(num[k]);
            if(sum == target)
            {
                res.push_back(out);
            }
            else
                helper(k + 1, sum, target, out, num, res);
        }
    }
};
