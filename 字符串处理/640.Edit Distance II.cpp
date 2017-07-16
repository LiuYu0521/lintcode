class Solution {
public:
    /**
     * @param s a string
     * @param t a string
     * @return true if they are both one edit distance apart or false
     */
    bool isOneEditDistance(string& s, string& t) {
        // Write your code here
        if(s.length() < t.length())
            swap(s, t);
        int m = s.length(), n = t.length(), diff = m - n;
        if(diff >= 2)
            return false;
        else if(diff == 1)
        {
            for(int i = 0; i < n; i++)
            {
                if(s[i] != t[i])
                    return s.substr(i + 1) == t.substr(i);
            }
        }
        else
        {
            int cnt = 0;
            for(int i = 0; i < m; i++)
            {
                if(s[i] != t[i])
                    cnt++;
            }
            return cnt == 1;
        }
    }
};
