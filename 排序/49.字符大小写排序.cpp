class Solution {
public:
    /**
     * @param chars: The letters array you should sort.
     */
    bool isLower(char a)
    {
        return a >= 'a' && a <= 'z';
    }
    void sortLetters(string &letters) {
        // write your code here
        int i = 0;
        int j = letters.length() - 1;
        while(i <= j)
        {
            while(i <= j && isLower(letters[i]))
                i++;
            while(i <= j && !isLower(letters[j]))
                j--;
            if(i <= j)
            {
                swap(letters[i], letters[j]);
                i++;
                j--;
            }
        }
    }
};
