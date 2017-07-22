class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return an integer
     */
    int longestConsecutive(vector<int> &num) {
        // write you code here
        int maxcnt = 1, thiscnt = 1;
        sort(num.begin(), num.end());
        for(int i = 0; i < num.size() - 1; i++)
        {
            if(num[i] == num[i + 1])
                continue;
            if(num[i] + 1 == num[i + 1])
                thiscnt++;
            else
                thiscnt = 1;
            if(thiscnt > maxcnt)
                maxcnt = thiscnt;
        }
        return maxcnt;
    }
};
