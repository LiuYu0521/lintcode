class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) return 0;
        int n = prices.size(), g[n][3] = {0}, l[n][3] = {0};
        for (int i = 1; i < prices.size(); ++i) {
            int diff = prices[i] - prices[i - 1];
            for (int j = 1; j <= 2; ++j) {
                l[i][j] = max(g[i - 1][j - 1] + max(diff, 0), l[i - 1][j] + diff);
                g[i][j] = max(l[i][j], g[i - 1][j]);
            }
        }
        return g[n - 1][2];
    }
};

/*
global[i][j] = max(local[i][j], global[i - 1][j]);
去当前局部最好的，和过往全局最好的中大的那个（因为最后一次交易如果包含当前天一定在局部最好的里面，否则一定在过往全局最优的里面）

local[i][j]=max(global[i-1][j-1]+max(diff,0),local[i-1][j]+diff)
可以这样来理解：
第 i 天卖第 j 支股票的话，一定是下面的一种：
1. 今天刚买的
那么 Local(i, j) = Global(i-1, j-1)
相当于啥都没干
2. 昨天买的
那么 Local(i, j) = Global(i-1, j-1) + diff
等于 Global(i-1, j-1) 中的交易，加上今天干的那一票
3. 更早之前买的
那么 Local(i, j) = Local(i-1, j) + diff
昨天别卖了，留到今天卖
*/
