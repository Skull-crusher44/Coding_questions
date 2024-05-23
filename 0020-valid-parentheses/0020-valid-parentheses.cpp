class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else // if i want to check with top element then stack must not be  empty
            {
                if (st.empty())   // s="()]" if stack is empty and we encounter  closing parenthesis
                    return false; // this shows ==> there is no chance of getting corresponding opening parenthesis
                if (s[i] == ')' && st.top() == '(')
                    st.pop();
                else if (s[i] == '}' && st.top() == '{')
                    st.pop();
                else if (s[i] == ']' && st.top() == '[')
                    st.pop();
                else
                    return false; // s="(])" if we have closing parenthesis but we don't find any corresponding opening parenthesis
            }
        }
        if (st.empty())
            return true; // s="((){}[])"  after this stack will be empty
        else
            return false; // s="((({}[]"   after this stack will have ((( and stack is not empty ==>not vlaid parenheses
    }
};