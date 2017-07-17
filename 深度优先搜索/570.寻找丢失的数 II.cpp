class Solution {
public:
    /**
     * @param n an integer
     * @param str a string with number from 1-n in
     *            random order and miss one number
     * @return an integer
     */
    int findMissing2(int n, string& str) {
        // Write your code here
        vector<bool> used(n + 1, false);
        return find(n, str, 0, used);
    }

    int find(int n, string& str, int index, vector<bool>& used) {

        if (index == str.size()) {
            vector<int> result;
            for (int i = 1; i <= n; ++i)
                if (!used[i])
                    result.push_back(i);
            if (result.size() == 1)
                return result[0];
            else
                return -1;
        }

        if (str[index] == '0')
            return -1;

        for (int i = 1; i < 3; ++i) {
            int num = getNumber(str, index, i);
            if (num >= 1 && num <= n && !used[num]) {
                used[num] = true;
                int target = find(n, str, index + i, used);
                if (target != -1)
                    return target;
                used[num] = false;
            }
        }
        return -1;
    }

    int getNumber(string& str, int start, int len) {
        return atoi(str.substr(start, len).c_str());
    }
};
