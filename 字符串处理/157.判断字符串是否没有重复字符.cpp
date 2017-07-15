class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        // write your code here
        vector<int> cnt(256, 0);
        for(auto c : str)
        {
            if(cnt[c] == 0)
                cnt[c] = 1;
            else
                return false;
        }
        return true;
    }
};

class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        // write your code here
        sort(str.begin(), str.end());
        for(int i = 0; i < str.length() - 1; i++)
        {
            if(str[i] == str[i + 1])
                return false;
        }
        return true;
    }
};
