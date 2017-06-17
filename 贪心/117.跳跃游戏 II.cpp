class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        // wirte your code here
        int n = A.size();
        int res = 0, i = 0, cur = 0;
        while(cur < n - 1)
        {
            int pre = cur;
            while(i <= pre)
            {
                cur = max(cur, i + A[i]);
                i++;
            }
            res++;
            if(cur == pre)
                return -1;
        }
        return res;
    }
};
