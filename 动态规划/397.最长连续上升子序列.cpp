class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        // Write your code here
        int len = A.size();
        if(len == 0 || len == 1)
            return len;
        int max_cnt = 1,this_cnt = 1;
        int flag = 0;
        for(int i = 0; i < len - 1; i++)
        {
            if(A[i] == A[i + 1])
            {
                flag = 0;
                this_cnt = 1;
            }
            else if(A[i] < A[i + 1])
            {
                if(flag == 1)
                    this_cnt++;
                else
                {
                    this_cnt = 2;
                    flag = 1;
                }
            }
            else
            {
                if(flag == -1)
                    this_cnt++;
                else
                {
                    this_cnt = 2;
                    flag = -1;
                }
            }
            max_cnt = max(max_cnt, this_cnt);
        }
        return max_cnt;
    }
};
