class Solution {
public:
       int is_possible(vector<int>v,int k,int day)
       {
           int n= v.size();
           int count=0;
           int no_of_bq=0;
           for(int i=0;i<n;i++)
           {
               if(v[i]<=day)
               {
                   count++;
               }
               else
               {
                   no_of_bq+=(count/k);
                   count=0;
               }
           }
           no_of_bq+=(count/k);
           return no_of_bq;
       }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n= bloomDay.size();
        if(long(m)*k>n)return -1;

        int mini=INT_MAX,maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            mini=min(mini,bloomDay[i]);
            maxi=max(maxi,bloomDay[i]);
        }
        int s=mini;
        int e=maxi;
        int ans=0;
        while(s<=e)
        {
            int mid = s +(e-s)/2;
            if(is_possible(bloomDay,k,mid)>=m)
            {
                ans=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return s;
       


    }
};