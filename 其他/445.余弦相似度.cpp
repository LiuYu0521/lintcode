class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: Cosine similarity.
     */
    double cosineSimilarity(vector<int> A, vector<int> B) {
        // write your code here
        int len = A.size();
        if(len == 0)
            return 2.0000;
        double muA = 0.0, muB = 0.0, mul = 0.0;
        double res = 0.0;
        for(int i = 0; i < len; i++)
        {
            mul = mul + A[i] * B[i];
            muA = muA + A[i] * A[i];
            muB = muB + B[i] * B[i];
        }
        if(muA == 0 || muB == 0)
            res = 2.0000;
        else
            res = mul / (sqrt(muA) * sqrt(muB));
        return res;
    }
};
