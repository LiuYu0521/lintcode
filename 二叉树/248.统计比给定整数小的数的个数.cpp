class Solution {
public:
   /**
     * @param A: An integer array
     * @return: The number of element in the array that
     *          are smaller that the given integer
     */
    int find(vector<int> &A, int val)
    {
        int l = 0;
        int r = A.size() - 1;
        int ans = -1;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(A[mid] < val)
            {
                l = mid + 1;
                ans = mid;
            }
            else
                r = mid - 1;
        }
        return ans + 1;
    }
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        // write your code here
        vector<int> res;
        sort(A.begin(), A.end());
        int qlen = queries.size();
        for(int i = 0; i < qlen; i++)
        {
            res.push_back(find(A, queries[i]));
        }
        return res;
    }
};
