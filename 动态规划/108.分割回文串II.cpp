class Solution {
public:
    /**
     * @param s a string
     * @return an integer
     */
    int minCut(string s) {
        // write your code here
        int res = 0;
        int len = s.length();
        int cuts[len + 1];
        bool dp[len][len];
        memset(dp,0,sizeof(dp));
        for(int i = 0; i <= len; i++)
        {
            cuts[i] = len - i;
        }
        for(int i = len - 1; i >= 0; i--)
        {
            for(int j = i; j < len; j++)
            {
                if((s[i] == s[j] && (j - i) < 2) || (s[i] == s[j] && dp[i + 1][j - 1]))
                {
                    dp[i][j] = true;
                    cuts[i] = min(cuts[i], cuts[j+1]+1);
                }
            }
        }
        return cuts[0] - 1;
    }
};
