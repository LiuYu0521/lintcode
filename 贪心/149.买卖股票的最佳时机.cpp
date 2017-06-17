class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        int res = 0, buy = INT_MAX;
        for(int price : prices)
        {
            buy = min(buy, price);
            res = max(res, price - buy);
        }
        return res;
    }
};
