class Solution {
public:
    /**
     * @param n an integer
     * @return true if this is a happy number or false
     */
    bool isHappy(int n) {
        // Write your code here
        if(n == 1)
            return true;
        set<int> s;
        s.insert(n);
        while(n != 1)
        {
            int sum = 0;
            while(n != 0)
            {
                sum = sum + (n % 10) * (n % 10);
                n = n / 10;
            }
            n = sum;
            if(n == 1)
                return true;
            if(s.find(n) != s.end())
                return false;
            else
                s.insert(n);
        }
    }
};
