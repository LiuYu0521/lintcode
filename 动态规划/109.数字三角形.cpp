class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        // write your code here
        int len = triangle.size();
        if(len == 0)
            return 0;
        int sum[len];
        for(int i = 0; i < len; i++)
        {
            sum[i] = triangle[len - 1][i];
        }
        for(int i = len - 2; i >= 0; i--)
        {
            for(int j = 0; j < i + 1; j++)
            {
                sum[j] = triangle[i][j] + min(sum[j], sum[j + 1]);
            }
        }
        return sum[0];
    }
};
