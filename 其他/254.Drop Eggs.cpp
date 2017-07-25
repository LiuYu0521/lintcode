class Solution {
public:
    /**
     * @param n an integer
     * @return an integer
     */
    int dropEggs(int n) {
        // Write your code here
        int k = 1;
        while((long long)k * (k + 1) / 2 < n)
        {
            k++;
        }
        return k;
    }
};
