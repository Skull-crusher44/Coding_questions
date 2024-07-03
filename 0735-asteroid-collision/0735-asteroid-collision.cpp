class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;
        int n= asteroids.size();
        
        for(int i=0;i<n;i++)
        {
            bool flag=true;
            while(!s.empty()&&s.top()>0&&asteroids[i]<0)
            {
                if(s.top()+asteroids[i]==0)
                {
                    s.pop();
                    flag=false;
                    break;
                }
                else if(s.top() <= -asteroids[i])
                s.pop();
                else
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            s.push(asteroids[i]);
        }

        vector<int>ans(s.size(),0);
        while(!s.empty())
        {
            ans[s.size()-1]=s.top();
            s.pop();
        }
        return ans;
    }
};