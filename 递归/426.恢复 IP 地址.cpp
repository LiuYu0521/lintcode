/**
*根据目前刷了这么多题，得出了两个经验，一是只要遇到字符串的子序列或配准问题首先考虑动态规划DP，二是只要遇到需要求出所有可能情况首先考虑递归
*/
/**
     * 利用循环递归解决子问题。
     * 首先我们要明确传统 IP 地址的规律是分 4 个 Part，每个 Part 是从 0-255 的数字
     *0-255 的数字，转换成字符，即每个 Part 可能由一个字符组成，二个字符组成，或者是三个字符组成。
     * 对于每个段内数来说，最多 3 位最少 1 位，所以在每一层可以循环 3 次，来尝试填段。
     * 因为 IP 地址最多 4 个分段，当层数是 3 的时候说明已经尝试填过 3 个段了，那么把剩余没填的数段接到结尾即可。
     * 这个过程中要保证的是填的数是合法的，最后拼接的剩余的数也是合法的。
     * 注意开头如果是 0 的话要特殊处理，如果开头是 0，判断整个串是不是 0，不是的话该字符就是非法的。因为 001，01 都是不对的。
*/
class Solution {
public:
    /**
     * @param s the IP string
     * @return All possible valid IP addresses
     */
    vector<string> restoreIpAddresses(string& s) {
        // Write your code here
        vector<string> res;
        restore(s, 4, "", res);
        return res;
    }
    void restore(string s, int k, string out, vector<string> &res)
    {
        if(k == 0)
        {
            if(s.empty())
                res.push_back(out);
        }
        else
        {
            for(int i = 1; i <= 3; i++)
            {
                if(s.size() >= i && isValid(s.substr(0, i)))
                {
                    if(k == 1)
                        restore(s.substr(i), k - 1, out + s.substr(0, i), res);
                    else
                        restore(s.substr(i), k - 1, out + s.substr(0, i) + ".", res);
                }
            }
        }
    }
    bool isValid(string s)
    {
        if(s.empty() || s.length() > 3 || (s.length() > 1 && s[0] == '0'))
            return false;
        int num = stoi(s);
        return num >= 0 && num <= 255;
    }
};
