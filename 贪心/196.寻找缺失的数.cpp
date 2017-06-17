class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        // write your code here
        int N = nums.size();
        int res = 0;
        for(int i = 0; i < N; i++)
        {
            res = res^i^nums[i];
        }
        return res^N;
    }
};
