class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        // write your code here
        int count = 0;
        if(k == 0)
            count = 1;
        for(int i = 1; i <= n; i++)
        {
            int temp = i;
            while(temp != 0)
            {
                if(temp % 10 == k)
                    count++;
                temp = temp / 10;
            }
        }
        return count;
    }
};
