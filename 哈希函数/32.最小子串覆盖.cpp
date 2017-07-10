class Solution {
public:
    /**
     * @param source: A string
     * @param target: A string
     * @return: A string denote the minimum window
     *          Return "" if there is no such a string
     */
    string minWindow(string &source, string &target) {
        // write your code here
        if(source.length() < target.length())
            return "";
        string res = "";
        int left = 0, count = 0, minLen = source.size() + 1;
        unordered_map<char, int> m;
        for(char c : target)
            m[c]++;
        for(int right = 0; right < source.length(); right++)
        {
            if(m.find(source[right]) != m.end())
            {
                m[source[right]]--;
                if(m[source[right]] >= 0)
                    count++;
                while(count == target.length())
                {
                    if(right - left + 1 < minLen)
                    {
                        minLen = right - left + 1;
                        res = source.substr(left, minLen);
                    }
                    if(m.find(source[left]) != m.end())
                    {
                        m[source[left]]++;
                        if(m[source[left]] > 0)
                            count--;
                    }
                    left++;
                }
            }
        }
        return res;
    }
};
