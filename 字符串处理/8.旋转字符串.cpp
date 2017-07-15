class Solution {
public:
    /**
     * @param str: a string
     * @param offset: an integer
     * @return: nothing
     */
    void rotateString(string &str,int offset){
        //wirte your code here
        if(str.length() == 0)
            return;
        int len = str.length();
        int off = offset % len;
        reverse(str.begin(), str.end() - off);
        reverse(str.end() - off, str.end());
        reverse(str.begin(), str.end());
    }
};
