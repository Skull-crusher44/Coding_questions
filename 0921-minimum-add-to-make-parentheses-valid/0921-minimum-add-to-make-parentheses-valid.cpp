class Solution {
public:
    int minAddToMakeValid(string s) {

        stack<char> st;
        int count=0;            //store no of closing parenthesis
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (ch == '(') 
                st.push(ch);
            else {
                if (st.empty())
                    count++;
                else
                    st.pop(); 
                }
        }
        int no_of_open_parenth=st.size();
        return (count+no_of_open_parenth);
        
    }
};