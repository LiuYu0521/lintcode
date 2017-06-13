class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        // write your code here
        sort(S.begin(), S.end());
        int res = 0;
        int len = S.size();
        for(int i = 0; i < len; i++)
        {
            for(int j = i + 1; j < len; j++)
            {
                int l = i + 1;
                int r = j;
                int target = S[j] - S[i];
                while(l < r)
                {
                    int mid = (l + r) / 2;
                    if(S[mid] > target)
                        r = mid;
                    else
                        l = mid + 1;
                }
                res = res + (j - r);
            }
        }
        return res;
    }
};
