class Solution {
public:
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    int evalRPN(vector<string>& tokens) {
        // Write your code here
        if(tokens.size() == 1)
            return atoi(tokens[0].c_str());
        stack<int> s;
        for(int i = 0; i < tokens.size(); i++)
        {
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
            {
                s.push(atoi(tokens[i].c_str()));
            }
            else
            {
                int m = s.top();
                s.pop();
                int n = s.top();
                s.pop();
                if (tokens[i] == "+") s.push(n + m);
                if (tokens[i] == "-") s.push(n - m);
                if (tokens[i] == "*") s.push(n * m);
                if (tokens[i] == "/") s.push(n / m);
            }
        }
        return s.top();
    }
};
