class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        // Write your code here
        int cnt = 0;
        int len = s.length();
        for(int i = len - 1; i >= 0; i--)
        {
            if(s[i] != ' ')
                cnt++;
            else
                break;
        }
        return cnt;
    }
};
