class Solution {
public:
    /**
     * @param matrix an integer matrix
     * @return the coordinate of the left-up and right-down number
     */
    vector<int> subarraySum(vector<int>& nums) {

        map<int,int> mp;
        mp[0] = -1;
        vector<int> results;
        results.push_back(-1);
        results.push_back(-1);
        int sum = 0, len = nums.size();
        for (int i = 0; i < len; ++i) {
            sum += nums[i];
            if  (mp.find(sum) != mp.end()) {
                results[0] = mp[sum] + 1;
                results[1] = i;
                return results;
            }
            mp[sum] = i;
        }
        return results;
    }

    vector<vector<int>> submatrixSum(vector<vector<int>>& matrix) {
        // Write your code here
        vector<vector<int>> result;
        vector<int> tmp(2, 1);
        result.push_back(tmp);
        result.push_back(tmp);
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> sum = matrix;
        for (int j = 0; j < m; ++j)
            for (int i = 1; i < n; ++i)
                sum[i][j] += sum[i-1][j];

        vector<int> A;
        for (int j = 0; j < m; ++j)
            A.push_back(0);

        for (int x1 = 0; x1 < n; ++x1)
            for (int x2 = x1; x2 < n; ++x2) {
                for (int j = 0; j < m; ++j)
                    if (x1 == 0)
                        A[j] = sum[x2][j];
                    else
                        A[j] = sum[x2][j] - sum[x1-1][j];

                    vector<int> r = subarraySum(A);
                    if (r[0] != -1) {
                        result[0][0] = x1;
                        result[0][1] = r[0];
                        result[1][0] = x2;
                        result[1][1] = r[1];
                        //matrix[1][1] = 1000;
                        return result;
                    }
        }
        //matrix[1][1] = 1000;
        return result;
    }
};
