class Solution {
public:
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    bool isNumber(char c)
    {
        return c >= '0' && c <= '9';
    }
    bool isLetter(char c)
    {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
    bool isNumSame(char a, char b)
    {
        return isNumber(a) && isNumber(b) && a == b;
    }
    bool isLetSame(char a, char b)
    {
        return isLetter(a) && isLetter(b) && (a == b || abs(a - b) == abs('A' - 'a'));
    }
    bool isPalindrome(string& s) {
        // Write your code here
        int len = s.length();
        if(len == 0 || len == 1)
            return true;
        int left = 0;
        int right = len - 1;
        while(left < right)
        {
            while(!(isNumber(s[left]) || isLetter(s[left])) && left <= len - 1)
                left++;
            while(!(isNumber(s[right]) || isLetter(s[right])) && right >= 0)
                right--;
            if(left == right || left - right == len + 1)
            {
                return true;
            }
            else if(left < right)
            {
                if(isNumSame(s[left], s[right]) || isLetSame(s[left], s[right]))
                {
                    left++;
                    right--;
                }
                else
                    return false;
            }
            else
            {
                return false;
            }
        }
    }
};
