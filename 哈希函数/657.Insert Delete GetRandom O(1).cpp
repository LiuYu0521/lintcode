class RandomizedSet {
public:
    RandomizedSet() {
        // do initialize if necessary
    }

    // Inserts a value to the set
    // Returns true if the set did not already contain the specified element or false
    bool insert(int val) {
        // Write your code here
        if(m.find(val) != m.end())
            return false;
        nums.push_back(val);
        m[val] = nums.size() - 1;
        return true;
    }

    // Removes a value from the set
    // Return true if the set contained the specified element or false
    bool remove(int val) {
        // Write your code here
        if(m.find(val) == m.end())
            return false;
        int last = nums.back();
        m[last] = m[val];
        nums.pop_back();
        m.erase(val);
        return true;
    }

    // Get a random element from the set
    int getRandom() {
        // Write your code here
        return nums[rand() % nums.size()];
    }
private:
    vector<int> nums;
    unordered_map<int, int> m;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param = obj.insert(val);
 * bool param = obj.remove(val);
 * int param = obj.getRandom();
 */
