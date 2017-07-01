class Solution {
public:
    /**
     * @param num1 a non-negative integers
     * @param num2 a non-negative integers
     * @return return product of num1 and num2
     */
    string multiply(string& num1, string& num2) {
        // Write your code here
        if(num1 == "0" || num2 == "0")
            return "0";
        int len1 = num1.length();
        int len2 = num2.length();
        char res[len1 + len2];
        for(int i = 0; i < len1 + len2; i++)
        {
            res[i] = '0';
        }
        for(int i = len1 - 1; i >= 0; i--)
        {
            int p = 0;
            for(int j = len2 - 1; j >= 0; j--)
            {
                int temp = (res[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + p;
                p = temp / 10;
                res[i + j + 1] = char(temp % 10 + '0');
            }
            res[i] = res[i] + p;
        }
        string out = "";
        int count = 0;
        for(; count < len1 + len2; count++)
        {
            if(res[count] != '0')
                break;
        }
        for(int i = count; i < len1 + len2; i++)
        {
            out = out + res[i];
        }
        return out;
    }
};
