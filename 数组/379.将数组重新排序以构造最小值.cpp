class Solution {
public:
    /**
     * @param nums n non-negative integer array
     * @return a string
     */
    static bool cmp(const string &a, const string &b)
    {
        return (a + b) < (b + a);
    }
    string minNumber(vector<int>& nums) {
        // Write your code here
        if(nums.empty())
            return "";
        vector<string> num_str(nums.size());
        for(int i = 0; i < nums.size(); i++)
        {
            num_str[i] = to_string(nums[i]);
        }
        sort(num_str.begin(), num_str.end(), cmp);
        string res;
        int index = 0;
        while(index < num_str.size() && num_str[index] == "0")
            index++;
        while(index < num_str.size())
        {
            res = res + num_str[index];
            index++;
        }
        if(res.empty())
            return "0";
        return res;
    }
};
