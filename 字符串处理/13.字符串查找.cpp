class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
        if(!source || !target)
            return -1;
        int s_len = strlen(source);
        int t_len = strlen(target);
        int i, j;
        for(i = 0; i < s_len - t_len + 1; i++)
        {
            for(j = 0; j < t_len; j++)
            {
                if(source[i + j] != target[j])
                    break;
            }
            if(j == t_len)
                return i;
        }
        return -1;
    }
};
