class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        // write your code here
        vector<int> res;
        if(n == 0)
            return res;
        if(n == 1)
        {
            for(int i = 1; i <= 9; i++)
            {
                res.push_back(i);
            }
            return res;
        }
        vector<int> temp = numbersByRecursion(n - 1);
        res.insert(res.end(), temp.begin(), temp.end());
        for(int i = 1; i <= 9; i++)
        {
            res.push_back((int)pow(10, n - 1) * i);
            for(auto sub : temp)
                res.push_back((int)pow(10, n - 1) * i + sub);
        }
        return res;
    }
};
