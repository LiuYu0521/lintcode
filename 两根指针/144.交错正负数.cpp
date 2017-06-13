class Solution {
public:
    /**
     * @param A: An integer array.
     * @return: void
     */
    void rerange(vector<int> &A) {
        // write your code here
        int len = A.size();
        if(len <= 2)
            return;
        int pos_count = 0;
        for(int i = 0; i < len; i++)
        {
            if(A[i] > 0)
            {
                pos_count++;
            }
        }
        int neg_count = len - pos_count;
        if(pos_count > neg_count)
        {
            int left = 0;
            int right = len - 1;
            while(left < right)
            {
                while(left < right && A[left] > 0)
                    left++;
                while(left < right && A[right] < 0)
                    right--;
                if(left <= right)
                {
                    swap(A[left], A[right]);
                    left++;
                    right--;
                }
            }
            left = 1;
            right = len - 1;
            while(left < right)
            {
                swap(A[left], A[right]);
                left = left + 2;
                right = right - 2;
            }
        }
        else
        {
            int left = 0;
            int right = len - 1;
            while(left < right)
            {
                while(left < right && A[left] < 0)
                    left++;
                while(left < right && A[right] > 0)
                    right--;
                if(left <= right)
                {
                    swap(A[left], A[right]);
                    left++;
                    right--;
                }
            }
            left = 1;
            right = len - 1;
            if(pos_count == neg_count)
                right--;
            while(left < right)
            {
                swap(A[left], A[right]);
                left = left + 2;
                right = right - 2;
            }
        }
    }
};
