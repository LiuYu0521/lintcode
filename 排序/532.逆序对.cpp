class Solution {
private:
    int* tmp;
public:
    /**
     * @param A an array
     * @return total of reverse pairs
     */
    long long reversePairs(vector<int>& A) {
        // Write your code here
        int n = A.size();
        tmp = new int[n];
        return mergeSort(A, 0, n-1);
    }

    long long merge(vector<int> &A, int l, int m, int r) {
        int i = l, j = m + 1, k = l;
        long long ans = 0;
        while (i <= m && j <= r) {
            if (A[i] > A[j]) {
                tmp[k++] = A[j++];
                ans += m - i + 1;
            } else {
                tmp[k++] = A[i++];
            }
        }
        while (i <= m) tmp[k++] = A[i++];
        while (j <= r) tmp[k++] = A[j++];
        for (i = l;i <= r; ++i)
            A[i] = tmp[i];
        return ans;
    }

    long long mergeSort(vector<int> &A, int l,int r) {
        long long ans = 0;
        if (l < r) {
            int m = (l + r) >> 1;
            ans += mergeSort(A, l, m);
            ans += mergeSort(A, m + 1, r);
            ans += merge(A, l, m, r);
        }
        return ans;
    }
};
