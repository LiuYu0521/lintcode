class Solution {
public:
    /**
     * @param num1 a non-negative integers
     * @param num2 a non-negative integers
     * @return return sum of num1 and num2
     */
    string addStrings(string& num1, string& num2) {
        // Write your code here
        if(num1 == "0")
            return num2;
        if(num2 == "0")
            return num1;
        int len1 = num1.length();
        int len2 = num2.length();
        int len = max(len1, len2);
        char res[len + 1];
        for(int i = 0; i < len + 1; i++)
        {
            res[i] = '0';
        }
        int carry = 0, a = 0, b = 0;
        for(int i = 0; i < len + 1; i++)
        {
            if(i < len1)
                a = num1[len1 - i - 1] - '0';
            else
                a = 0;
            if(i < len2)
                b = num2[len2 - i - 1] - '0';
            else
                b = 0;
            int temp = carry + a + b;
            res[len - i] = (char)(temp % 10 + '0');
            carry = temp / 10;
        }
        int count = 0;
        for(;count < len + 1; count++)
        {
            if(res[count] != '0')
                break;
        }
        string out = "";
        for(int i = count; i < len + 1; i++)
        {
            out = out + res[i];
        }
        return out;
    }
};
