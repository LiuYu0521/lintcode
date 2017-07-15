class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true
     *           else return false
     */
    bool compareStrings(string A, string B) {
        // write your code here
        int letter[26]={0};
        for(auto c : A)
        {
            letter[c - 'A']++;
        }
        for(auto c : B)
        {
            if(letter[c - 'A'] == 0)
                return false;
            else
                letter[c - 'A']--;
        }
        return true;
    }
};
