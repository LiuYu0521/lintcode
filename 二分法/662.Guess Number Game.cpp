// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    /**
     * @param n an integer
     * @return the number you guess
     */
    int guessNumber(int n) {
        // Write your code here
        int left = 1;
        int right = n;
        int mid = left + (right - left) / 2;
        while(left <= right)
        {
            if(guess(mid) == 0)
                return mid;
            else if(guess(mid) == -1)
                right = mid - 1;
            else
                left = mid + 1;
            mid = left + (right - left) / 2;
        }
    }
};
