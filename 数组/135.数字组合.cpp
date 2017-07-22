class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // write your code here
        vector<vector<int>> res;
        vector<int> out;
        sort(candidates.begin(), candidates.end());
        help(0, target, candidates, out, res);
        return res;
    }
    void help(int start, int target, vector<int> &candidates, vector<int> &out, vector<vector<int>> &res)
    {
        if(target == 0)
            res.push_back(out);
        else if(target < 0)
            return;
        else
        {
            for(int i = start; i < candidates.size(); i++)
            {
                if(i > start && candidates[i - 1] == candidates[i])
                    continue;
                out.push_back(candidates[i]);
                help(i, target - candidates[i], candidates, out, res);
                out.pop_back();
            }
        }
    }
};
