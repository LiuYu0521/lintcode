class Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        int left = 0, right = num.size() - 1;
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(num[mid] > num[right])
                left = mid + 1;
            else if(num[mid] < num[right])
                right = mid;
            else
                right--;
        }
        return num[left];
    }
};
