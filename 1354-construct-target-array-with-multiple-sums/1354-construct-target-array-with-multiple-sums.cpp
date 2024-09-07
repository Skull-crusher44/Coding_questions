class Solution {
public:
    //donot go from question to solution 
    // think about going from solution to question 
    bool isPossible(vector<int>& target) {

        long long  sum=0;
        for(long long x:target)
        {
            sum+=x;
        }
        priority_queue<long long>q(target.begin(),target.end());
       
        while(q.top()!=1)
        {
            long long maxEle=q.top();
            q.pop();

            int remSum=sum-maxEle;
            //maxelement=remsum+element
            if(remSum>=maxEle)
            return 0;

            int element=maxEle-remSum;
            sum=sum-maxEle+element;
            q.push(element);
        }
        return true;
    }
};