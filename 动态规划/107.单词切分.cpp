class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    int getMaxLength(unordered_set<string> &dict)
    {
        int maxLength = 0;
        for(unordered_set<string>::iterator it = dict.begin(); it != dict.end(); it++)
        {
            int len_temp = (*it).length();
            maxLength = max(maxLength, len_temp);
        }
        return maxLength;
    }
    bool wordBreak(string s, unordered_set<string> &dict) {
        // write your code here
        int maxLength = getMaxLength(dict);
        int len = s.length();
        bool dp[len + 1];
        dp[0] = true;
        for(int i = 1; i <= len; i++)
        {
            dp[i] = false;
            for(int j = 1; j <= i && j <= maxLength; j++)
            {
                if(!dp[i - j])
                    continue;
                string word = s.substr(i - j, j);
                if(dict.find(word) != dict.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[len];
    }
};
