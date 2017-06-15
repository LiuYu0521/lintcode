/**
 * class SVNRepo {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use SVNRepo::isBadVersion(k) to judge whether
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
        int left = 1;
        int right = n;
        int mid = 0;
        while(left < right)
        {
            mid = left + (right - left) / 2;
            if(SVNRepo::isBadVersion(mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
