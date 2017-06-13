class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer
     */
    int lengthOfLongestSubstring(string s) {
        // write your code here
        int len = s.length();
        if(len <= 1)
            return len;
        int last[256], res = 0, left = 0;
        fill(last, last + 256, -1);
        for(int i = 0; i < len; i++)
        {
            if(last[s[i]] >= left)  left =  last[s[i]] + 1;
            last[s[i]] = i;
            res = max(res, i - left + 1);
        }
        return res;
    }
};
