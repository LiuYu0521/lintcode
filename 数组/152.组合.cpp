class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int> > combine(int n, int k) {
        // write your code here
        vector<vector<int>> res;
        vector<int> out;
        help(1, n, k, out, res);
        return res;
    }
    void help(int start, int n, int k, vector<int> &out, vector<vector<int>> &res)
    {
        if(k == 0)
            res.push_back(out);
        else if(start > n)
            return;
        else
        {
            for(int i = start; i <= n; i++)
            {
                out.push_back(i);
                help(i + 1, n, k - 1, out, res);
                out.pop_back();
            }
        }
    }
};
