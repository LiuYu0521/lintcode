class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        int len=values.size();
        if(len<=2) return true;
        int dp[len+1];//dp[i]表示从i到end能拿到的最大值
        dp[len]=0;
        dp[len-1]=values[len-1];
        dp[len-2]=values[len-1]+values[len-2];
        dp[len-3]=values[len-2]+values[len-3];
        for(int i=len-4;i>=0;i--)
        {
            dp[i]=max(values[i]+min(dp[i+2],dp[i+3]),values[i]+values[i+1]+min(dp[i+3],dp[i+4]));
        }
        int sum=0;
        for(int a:values) sum=sum+a;
        return dp[0]>sum-dp[0];
    }
};
