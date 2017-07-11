class Solution {
public:
    /**
     * @param digits A digital string
     * @return all posible letter combinations
     */
    vector<string> letterCombinations(string& digits) {
        // Write your code here
        vector<string> res;
        if(digits.empty())
            return res;
        string dict[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        helper(digits, dict, 0, "", res);
        return res;
    }
    void helper(string digits, string dict[], int level, string out, vector<string> &res)
    {
        if(level == digits.length())
            res.push_back(out);
        else
        {
            string str = dict[digits[level] - '2'];
            for(int i = 0; i < str.length(); i++)
            {
                out.push_back(str[i]);
                helper(digits, dict, level + 1, out, res);
                out.pop_back();
            }
        }
    }
};
