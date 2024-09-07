class KthLargest {
public:
    
    priority_queue<int,vector<int>,greater<int>>q;
    KthLargest(int k, vector<int>& nums) {
        
       for(int i=0;i<k;i++)
       {
           q.push(nums[i]);
       }
        for(int i=k;i<nums.size();i++)
       {
           if(nums[i]>q.top())
           {
               q.pop();
               q.push(nums[i]);
           }
       }
    }
    
    int add(int val) {
        if(val>q.top())
           {
               q.pop();
               q.push(val);
           }
           return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */