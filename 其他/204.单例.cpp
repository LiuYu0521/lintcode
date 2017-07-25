class Solution {
public:
    /**
     * @return: The same instance of this class every time
     */
    static Solution* instance;
    static Solution* getInstance() {
        if (instance == NULL) {
            instance = new Solution();
        }
        return instance;
    }
};

Solution* Solution::instance = NULL;
