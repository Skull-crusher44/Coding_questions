class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>q;
        int sum=0;
        for(int x:piles)
        {
            q.push(x);
            sum+=x;
        }
        int remove =0;
        while(k--)
        {
            int max_stone=q.top();
            q.pop();
            remove+=max_stone/2;
            q.push(max_stone-remove);
        }
        return sum-remove;
    }
};