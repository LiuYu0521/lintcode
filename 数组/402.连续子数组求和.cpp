class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        // Write your code here
        vector<int> res;
        int start = 0, end = 0, maxsum = INT_MIN, thissum = 0;
        int nextstart = 0;
        for(int i = 0; i < A.size(); i++)
        {
            thissum = thissum + A[i];
            if(thissum > maxsum)
            {
                maxsum = thissum;
                end = i;
                start = nextstart;
            }
            if(thissum < 0)
            {
                thissum = 0;
                nextstart = i + 1;
            }
        }
        res.push_back(start);
        res.push_back(end);
        return res;
    }
};
