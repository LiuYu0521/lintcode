class Solution {
public:
    /**
     * @param s a string
     * @param t a string
     * @return true if the characters in s
     * can be replaced to get t or false
     */
    bool isIsomorphic(string& s, string& t) {
        // Write your code here
        if(s.length() != s.length())
            return false;
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        for(auto c : s)
            m1[c]++;
        for(auto c : t)
            m2[c]++;
        for(int i = 0; i < m1.size(); i++)
        {
            if(m1[s[i]] != m2[t[i]])
                return false;
        }
        return true;
    }
};
