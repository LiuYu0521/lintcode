class Solution {
public:
    /**
     * @param s a string
     * @param p a non-empty string
     * @return a list of index
     */
    vector<int> findAnagrams(string& s, string& p) {
        // Write your code here
        vector<int> res;
        if(s.length() == 0 || p.length() == 0)
            return res;
        vector<int> m1(256, 0), m2(256,0);
        for(int i = 0; i < p.size(); i++)
        {
            m1[s[i]]++;
            m2[p[i]]++;
        }
        if(m1 == m2)
            res.push_back(0);
        for(int i = p.size(); i < s.size(); i++)
        {
            m1[s[i]]++;
            m1[s[i - p.size()]]--;
            if(m1 == m2)
                res.push_back(i - p.size() + 1);
        }
        return res;
    }
};

/*下面这种利用滑动窗口 Sliding Window 的方法也比较巧妙，首先统计字符串 p 的字符个数，然后用两个变量 left 和 right  表示滑动窗口的左右边界，用变量 cnt 表示字符串 p 中需要匹配的字符个数，然后开始循环，如果右边界的字符已经在哈希表中了，说明该字符在 p 中有出现，则 cnt 自减 1，然后哈希表中该字符个数自减 1，右边界自加 1，如果此时 cnt 减为 0 了，说明 p 中的字符都匹配上了，那么将此时左边界加入结果 res 中。如果此时right 和 left 的差为 p            的长度，说明此时应该去掉最左边的一个字符，我们看如果该字符在哈希表中的个数大于等于 0，说明该字符是 p 中的字符，为啥呢，因为上面我们有让每个字符自减 1，如果不是 p 中的字符，那么在哈希表中个数应该为 0，自减 1 后就为 - 1，所以这样就知道该字符是否属于p，如果我们去掉了属于 p 的一个字符，cnt 自增 1，参见代码如下：
*/
class Solution {
public:
    vector<int> findAnagrams(string &s, string &p) {
        if (s.empty()) return {};
        vector<int> res, m(256, 0);
        int left = 0, right = 0, cnt = p.size(), n = s.size();
        for (char c : p) ++m[c];
        while (right < n) {
            if (m[s[right++]]-- >= 1) --cnt;
            if (cnt == 0) res.push_back(left);
            if (right - left == p.size() && m[s[left++]]++ >= 0) ++cnt;
        }
        return res;
    }
};
