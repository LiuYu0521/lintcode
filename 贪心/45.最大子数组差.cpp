class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
int maxDiffSubArrays(vector<int> nums) {
    const int n = nums.size();
    if (n < 2) {
        return 0;
    }
    vector<int> lMax(n), rMax(n), lMin(n), rMin(n);
    for (int i = 0, peek = INT_MIN, cur = 0; i < n; i++) {
        cur += nums[i];
        peek = max(peek, cur);
        lMax[i] = peek;
        if (cur < 0) {
            cur = 0;
        }
    }
    for (int i = n - 1, peek = INT_MIN, cur = 0; i > 0; i--) {
        cur += nums[i];
        peek = max(peek, cur);
        rMax[i - 1] = peek;
        if (cur < 0) {
            cur = 0;
        }
    }
    for (int i = 0, peek = INT_MAX, cur = 0; i < n; i++) {
        cur += nums[i];
        peek = min(cur, peek);
        lMin[i] = peek;
        if (cur > 0) {
            cur = 0;
        }
    }
    for (int i = n - 1, peek = INT_MAX, cur = 0; i > 0; i--) {
        cur += nums[i];
        peek = min(peek, cur);
        rMin[i - 1] = peek;
        if (cur > 0) {
            cur = 0;
        }
    }
    int result = INT_MIN;
    for (int i = 0; i < n - 1; i++) {
        int temp = max(lMax[i] - rMin[i], rMax[i] - lMin[i]);
        result = max(result, temp);
    }
    return result;
}
};
