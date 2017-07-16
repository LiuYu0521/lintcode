class Solution {
public:
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        // write your code here
        if(strs.empty())
            return "";
        string res = "";
        for(int j = 0; j < strs[0].length(); j++)
        {
            char c = strs[0][j];
            for(int i = 1; i < strs.size(); i++)
            {
                if(c != strs[i][j] || j >= strs[i].length())
                    return res;
            }
            res = res + c;
        }
        return res;
    }
};
