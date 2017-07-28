class Solution {
public:
    /*
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        // write your code here
        int res = 0, left = 0;
        unordered_map<char, int> m;
        for(int i = 0; i < s.length(); i++)
        {
            m[s[i]]++;
            while(m.size() > k)
            {
                if(--m[s[left]] == 0)
                    m.erase(s[left]);
                ++left;
            }
            res = max(res, i - left + 1);
        }
        return res;
    }
};
