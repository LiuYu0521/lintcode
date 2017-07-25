class Solution {
public:
    /**
     * @param s a string
     * @return it's index
     */
    int firstUniqChar(string& s) {
        // Write your code here
        unordered_map<char, int> m;
        for(int i = 0; i < s.length(); i++)
        {
            if(m.find(s[i]) == m.end())
                m[s[i]] = 1;
            else
                m[s[i]]++;
        }
        for(int i = 0; i < s.length(); i++)
        {
            if(m[s[i]] == 1)
                return i;
        }
        return -1;
    }
};
