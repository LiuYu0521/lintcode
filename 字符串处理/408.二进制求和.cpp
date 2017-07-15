class Solution {
public:
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
        // Write your code here
        string res = "";
        int m = a.length() - 1, n = b.length() - 1, carry = 0;
        while(m >= 0 || n >= 0)
        {
            int p = m >= 0 ? a[m] - '0' : 0;
            int q = n >= 0 ? b[n] - '0' : 0;
            m--;
            n--;
            int sum = p + q + carry;
            res = to_string(sum % 2) + res;
            carry = sum / 2;
        }
        return carry ? "1" + res : res;
    }
};
