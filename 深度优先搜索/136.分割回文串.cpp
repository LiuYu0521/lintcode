class Solution {
public:
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string s) {
        // write your code here
        vector<vector<string>> res;
        vector<string> out;
        dfs(0, s, out, res);
        return res;
    }
    void dfs(int start, string &s, vector<string> &out, vector<vector<string>> &res)
    {
        if(start == s.length())
        {
            res.push_back(out);
            return;
        }
        else
        {
            for(int i = start; i < s.length(); i++)
            {
                if(isPalindrome(s, start, i))
                {
                    out.push_back(s.substr(start, i - start + 1));
                    dfs(i + 1, s, out, res);
                    out.pop_back();
                }
            }
        }
    }
    bool isPalindrome(string &s, int start, int end)
    {
        while(start < end)
        {
            if(s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
};
