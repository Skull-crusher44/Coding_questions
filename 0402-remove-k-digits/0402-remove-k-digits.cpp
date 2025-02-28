class Solution {
public:
    string removeKdigits(string num, int k) {
        int count=0;
        stack<int>s;
        if(k==num.length())return "0";
        for(int i =0 ; i < num.length() ; i++)
        {
            while(!s.empty()&& k && (num[i]-'0')<=s.top()){
                k--;
                s.pop();
            }
            s.push((num[i]-'0'));
        }
        string ans="";
        while(!s.empty()){
            ans+=to_string(s.top());
            s.pop();
        }
        int i;
        reverse(ans.begin(),ans.end());
        for( i =0 ; i < ans.length() ; i++)
        {
            if(ans[i]!='0')
            {
                break;
            }
        }
        return ans.substr(i);

    }
};