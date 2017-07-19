class Solution {
public:
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    vector<int> plusOne(vector<int>& digits) {
        // Write your code here
        int carry = 1;
        for(int i = digits.size() - 1; i >= 0; i--)
        {
            int temp = digits[i];
            digits[i] = (temp + carry) % 10;
            carry = (temp + carry) / 10;
        }
        if(carry == 1)
            digits.insert(digits.begin(), carry);
        return digits;
    }
};
