class MinStack {
public:
    MinStack() {
        // do initialization if necessary
    }

    void push(int number) {
        // write your code here
        s.push(number);
        if(s_min.empty() || number <= s_min.top())
            s_min.push(number);
    }

    int pop() {
        // write your code here
        if(s.top() == s_min.top())
            s_min.pop();
        int res = s.top();
        s.pop();
        return res;
    }

    int min() {
        // write your code here
        return s_min.top();
    }
private:
    stack<int> s, s_min;
};
