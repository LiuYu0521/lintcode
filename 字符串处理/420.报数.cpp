class Solution {
public:
    /**
     * @param n the nth
     * @return the nth sequence
     */
    string countAndSay(int n) {
        // Write your code here
        if(n <= 0)
            return "";
        string res = "1";
        for(int i = 0; i < n - 1; i++)
        {
            string temp = "";
            for(int j = 0; j < res.length(); j++)
            {
                int cnt = 1;
                char num = res[j];
                while(j < res.length() - 1 && res[j] == res[j + 1])
                {
                    j++;
                    cnt++;
                }
                temp = temp + to_string(cnt) + num;
            }
            res.clear();
            res = temp;
        }
        return res;
    }
};
