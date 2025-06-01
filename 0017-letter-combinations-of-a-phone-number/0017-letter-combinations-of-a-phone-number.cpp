class Solution {
public:
    vector<string>ans;
    void backtrack(string digits, string temp, int index,vector<vector<char>>&map){
        if(index>=digits.size()){
            ans.push_back(temp);
            return;
        } 

        //code
        int ele = digits[index]-'0';
        for(int i =0 ; i < map[ele].size() ; i++)
        {
            backtrack(digits,temp+map[ele][i],index+1,map);
        }
    }
    vector<string> letterCombinations(string digits) {
        //store the mapping of digits to character
        if(digits.empty())return ans;
        vector<vector<char>>mapping = {
        {'*'},
        {'*'},
        {'a','b','c'},
        {'d','e','f'},
        {'g','h','i'},
        {'j','k','l'},
        {'m','n','o'},
        {'p','q','r','s'},
        {'t','u','v'},
        {'w','x','y','z'}
        };
        backtrack(digits,"",0,mapping);
        return ans;
    }
};