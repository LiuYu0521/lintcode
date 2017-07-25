class Solution {
public:
    /**
     * @param x an integer
     * @param y an integer
     * @return nothing
     */
    void swap(int &x, int &y) {
        // Write your code here
        x = x ^ y;
        y = x ^ y;
        x = x ^ y;
    }
};
