class Solution {
public:
    vector<string> pad{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void  solve(string digits,vector<string>&ans,string output,int index=0){
        if(index>=digits.size())
        {
          ans.push_back(output);
          return;  
        }
        int num= (digits[index]-'0');
        string code=pad[num];
        for(int i=0;i<code.length();i++)
        {
            output.push_back(code[i]);
            solve(digits,ans,output,index+1);
            output.pop_back();

        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output;
        if(digits.length()==0)
        return ans;
        solve(digits,ans,output);
        return ans;
        
    }
};