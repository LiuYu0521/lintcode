class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        // write your code here
        int count = 0;
        int num = a ^ b;
        while(num != 0)
        {
            num = num & (num - 1);
            count++;
        }
        return count;
    }
};
