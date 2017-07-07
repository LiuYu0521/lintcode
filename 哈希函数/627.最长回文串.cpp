class Solution {
public:
    /**
     * @param s a string which consists of lowercase or uppercase letters
     * @return the length of the longest palindromes that can be built
     */
    int longestPalindrome(string& s) {
        // Write your code here
        int count = 0;
        bool flag = false;
        unordered_map<char, int> m;
        for(auto c : s)
            m[c]++;
        for(auto it = m.begin(); it != m.end(); it++)
        {
            count = count + it->second;
            if(it->second % 2 == 1)
            {
                flag = true;
                count--;
            }
        }
        return flag ? count + 1 : count;
    }
};
