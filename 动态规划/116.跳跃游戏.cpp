// class Solution {
// public:
//     /**
//      * @param A: A list of integers
//      * @return: The boolean answer
//      */
//     bool canJump(vector<int> A) {
//         // write you code here
//         int len = A.size();
//         if(len == 1)
//             return true;
//         int dp[len];
//         dp[0] = A[0];
//         for(int i = 1; i < len; i++)
//         {
//             if(dp[i - 1] >= i)
//                 dp[i] = max(dp[i - 1], i + A[i]);
//             else
//                 dp[i] = 0;
//         }
//         return dp[len - 1] >= len - 1;
//     }
// };

class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        // write you code here
        int len = A.size();
        int currtMaxStep = A[0];
        for(int i = 1; i < len; i++)
        {
            if(i > currtMaxStep)
                return false;
            currtMaxStep = max(currtMaxStep, i + A[i]);
            if(currtMaxStep >= len - 1)
                return true;
        }
        return currtMaxStep >= len - 1;
    }
};
