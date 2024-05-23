class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>a,b;
        for(char c:s)
        {
            if(c=='#')
            a.pop();
            else
            a.push(c);
        }
        for(char c:t)
        {
            if(c=='#')
            b.pop();
            else
            b.push(c);
        }
        if(a.size()!=b.size())
        return false;

        string x="",y="";
        while(!a.empty())
        {
            x+=a.top();
            a.pop();
        }
        while(!b.empty())
        {
            y+=b.top();
            b.pop();
        }
        return (x==y);

    }
};