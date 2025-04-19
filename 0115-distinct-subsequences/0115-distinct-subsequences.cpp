class Solution {
public:
    int count(int index, string &s, string ans, string target, int n ){
        if(index>=n)
        return (ans==target);

        return (count(index+1, s, ans+s[index], target, n)+ count(index+1, s, ans, target,n ));
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        return count(0,s,"",t,n);
    }
};