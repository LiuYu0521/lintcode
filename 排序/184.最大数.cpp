class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    string largestNumber(vector<int> &num) {
        // write your code here
        vector<string> st;
        for(int i = 0; i < num.size(); i++)
        {
            st.push_back(to_string(num[i]));
        }
        sort(st.begin(), st.end(), cmp);
        string result;
        for(int i = 0; i < num.size(); i++)
        {
            result = result + st[i];
        }
        if(result[0] == '0')
        {
            return "0";
        }
        return result;
    }
    static bool cmp(string& a, string& b)
    {
        return a + b > b + a;
    }
};
