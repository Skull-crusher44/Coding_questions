class Solution {
public:
    vector<vector<int>>ans;
    void backtrack(vector<int>& candidates, int remainSum, vector<int> temp,int index){
        if(remainSum==0) {
            ans.push_back(temp);
            return;
            }
        if(index>=candidates.size()){
            return ;
        }
        int currentElement = candidates[index];
        if(remainSum >= candidates[index]){
            temp.push_back(currentElement);
            backtrack(candidates,remainSum-currentElement,temp,index);
            temp.pop_back();
        }
        else{
            backtrack(candidates,remainSum,temp,index+1);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        backtrack(candidates,target,temp,0);
        return ans;
    }
};