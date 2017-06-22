class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        // write your code here
        int len = nums.size();
        map<int, int> m;
        for(auto num : nums)
        {
            if(m.find(num) == m.end())
            {
                m[num] = 1;
            }
            else
            {
                m[num]++;
            }
        }
        for(map<int, int>::iterator it = m.begin(); it != m.end(); it++)
        {
            if(it->second > len / k)
                return it->first;
        }
        return -1;
    }
};
