class Solution {
public:
    /**
     * @param num a positive number
     * @return true if it's a palindrome or false
     */
    bool palindromeNumber(int num) {
        // Write your code here
        if(num % 10 == 0)
            return false;
        string s = to_string(num);
        int i = 0, j = s.length() - 1;
        while(i < j)
        {
            if(s[i] == s[j])
            {
                i++;
                j--;
            }
            else
                return false;
        }
        return true;
    }
};
