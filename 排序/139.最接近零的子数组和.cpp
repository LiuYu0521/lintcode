class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number
     *          and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> nums){
        // write your code here
        vector<pair<int,int>> sum;
        int temp = 0;
        sum.push_back(make_pair(temp,-1));
        for(int i = 0; i < nums.size(); i++)
        {
            temp = temp + nums[i];
            sum.push_back(make_pair(temp, i));
        }
        sort(sum.begin(), sum.end());
        int start,end;
        int min_sub = INT_MAX;
        for(int i = 1; i < sum.size(); i++)
        {
            if(abs(sum[i].first - sum[i - 1].first) <= min_sub)
            {
                min_sub = abs(sum[i].first - sum[i - 1].first);
                start = min(sum[i].second, sum[i-1].second) + 1;
                end = max(sum[i].second, sum[i-1].second);
            }
        }
        vector<int> ret;
        ret.push_back(start);
        ret.push_back(end);
        return ret;
    }
};
