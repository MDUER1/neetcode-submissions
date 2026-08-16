class Solution {
public:
    bool isValid(string s) {
        std::stack<char> brackets;

        for (char c : s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                brackets.push(c);
            }
            
            else
            {
                if (brackets.empty())
                {
                    return false;
                }

                if ((c == ')' && brackets.top() != '(') ||
                    (c == ']' && brackets.top() != '[') ||
                    (c == '}' && brackets.top() != '{'))
                {
                    return false;
                }

                brackets.pop();
            }
        }

        return brackets.empty();
    }
};
