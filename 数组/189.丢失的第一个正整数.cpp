class Solution {
public:
    /**
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        // write your code here
        if(A.size() == 0)
            return 1;
        set<int> s;
        int mx = 0;
        for(int i = 0; i < A.size(); i++)
        {
            if(A[i] > 0)
            {
                s.insert(A[i]);
                mx = max(mx, A[i]);
            }
        }
        for(int i = 1; i <= mx; i++)
        {
            if(s.find(i) == s.end())
                return i;
        }
        return mx + 1;
    }
};
