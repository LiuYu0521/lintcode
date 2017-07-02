class Solution {
public:
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    bool isValidParentheses(string& s) {
        // Write your code here
        stack<char> help;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                help.push(s[i]);
            if(s[i] == ')')
            {
                if(help.top() == '(')
                    help.pop();
                else
                    return false;
            }
            else if(s[i] == ']')
            {
                if(help.top() == '[')
                    help.pop();
                else
                    return false;
            }
            else if(s[i] == '}')
            {
                if(help.top() == '{')
                    help.pop();
                else
                    return false;
            }
        }
        return help.empty();
    }
};
