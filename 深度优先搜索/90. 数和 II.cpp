class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer
     */
    vector<vector<int> > kSumII(vector<int> A, int k, int target) {
        // write your code here
        vector<vector<int>> res;
        vector<int> out;
        helper(0, k, target, A, out, res);
        return res;
    }
    void helper(int start, int k, int target, vector<int> &A, vector<int> &out, vector<vector<int>> &res)
    {
        if(target == 0 && k == 0)
        {
            res.push_back(out);
        }
        else if(target < 0 || k < 0)
        {
            return;
        }
        else
        {
            for(int i = start; i < A.size(); i++)
            {
                out.push_back(A[i]);
                helper(i + 1, k - 1, target - A[i], A, out, res);
                out.pop_back();
            }
        }
    }
};
