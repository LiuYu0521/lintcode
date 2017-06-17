class Solution {
public:
    /**
     * @param gas: a vector of integers
     * @param cost: a vector of integers
     * @return: an integer
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // write your code here
        int total = 0, sum = 0, start = 0;
        for(int i = 0; i < gas.size(); i++)
        {
            total = total + gas[i] - cost[i];
            sum = sum + gas[i] - cost[i];
            if(sum < 0)
            {
                start = i + 1;
                sum = 0;
            }
        }
        if(total < 0)
            return -1;
        else
            return start;
    }
};
