class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // write your code here
        vector<vector<int>> res;
        sort(S.begin(), S.end());
        vector<int> out;
        helper(0, out, S, res);
        return res;
    }
    void helper(int k, vector<int> &out, vector<int> &S, vector<vector<int>> &res)
    {
        res.push_back(out);
        for(int i = k; i < S.size(); i++)
        {
            out.push_back(S[i]);
            helper(i + 1, out, S, res);
            out.pop_back();
            while(S[i] == S[i + 1])
                i++;
        }
    }
};
