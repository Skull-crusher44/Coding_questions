class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>a,b;
        for(char c:s)
        {
            if(c=='#'&&!a.empty())
            a.pop();
            else if(c!='#')
            a.push(c);
        }
        for(char c:t)
        {
            if(c=='#'&&!b.empty())
            b.pop();
            else if(c!='#')
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