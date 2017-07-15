class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        int cnt = 0;
        vector<string> res;
        for(auto s : dictionary)
        {
            if(s.length() > cnt)
            {
                cnt = s.length();
                res.clear();
                res.push_back(s);
            }
            else if(s.length() == cnt)
            {
                res.push_back(s);
            }
        }
        return res;
    }
};
