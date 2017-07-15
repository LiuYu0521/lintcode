class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        // write your code here
        int index = 0, n = s.length();
        reverse(s.begin(), s.end());
        for(int i = 0; i < n; i++)
        {
            if(s[i] != ' ')
            {
                if(index != 0)
                {
                    s[index] = ' ';
                    index++;
                }
                int j = i;
                while(j < n && s[j] != ' ')
                {
                    s[index] = s[j];
                    index++;
                    j++;
                }
                reverse(s.begin() + index - (j - i), s.begin() + index);
                i = j;
            }
        }
        s.resize(index);
        return s;
    }
};
