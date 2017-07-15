class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        // write your code here
        vector<int> a(256, 0);
        vector<int> b(256, 0);
        for(auto c : s)
            a[c]++;
        for(auto c : t)
            b[c]++;
        return a == b;
    }
};
