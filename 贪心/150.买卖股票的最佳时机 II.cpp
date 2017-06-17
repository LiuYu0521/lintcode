class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        int len = prices.size();
        int res = 0;
        for(int i = 0; i < len - 1; i++)
        {
            if(prices[i + 1] > prices[i])
                res = res + (prices[i + 1] - prices[i]);
        }
        return res;
    }
};
