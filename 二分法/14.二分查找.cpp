class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        int left = 0;
        int right = array.size() - 1;
        int mid = left + (right - left) / 2;
        int index = -1;
        while(left <= right)
        {
            if(array[mid] == target)
            {
                index = mid;
                break;
            }
            else if(array[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
            mid = left + (right - left) / 2;
        }
        if(index != -1)
        {
            while(index > 0 && array[index - 1] == target)
            {
                index--;
            }
            return index;
        }
        return -1;
    }
};
