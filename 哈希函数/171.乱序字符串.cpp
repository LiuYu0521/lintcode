class Solution {
public:
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    string getSortedString(string &str)
    {
        vector<int> letter(26,0);
        for(int i = 0; i < str.length(); i++)
        {
            letter[str[i]-'a']++;
        }
        string res = "";
        for(int i = 0; i < 26; i++)
        {
            for(int j = 0; j < letter[i]; j++)
            {
                res = res + (char)('a' + i);
            }
        }
        return res;
    }
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        unordered_map<string, int> m;
        for(int i = 0; i < strs.size(); i++)
        {
            string temp = getSortedString(strs[i]);
            m[temp]++;
        }
        vector<string> res;
        for(int i = 0; i < strs.size(); i++)
        {
            string temp = getSortedString(strs[i]);
            if(m[temp] > 1)
                res.push_back(strs[i]);
        }
        return res;
    }
};
