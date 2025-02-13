class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long int , vector<long long int>, greater<long long int> >q;
        for(int i =0 ; i < nums.size() ; i++)
        {
            q.push(nums[i]);
        }
        int count_of_operations=0;
        while(q.top()<k){
            long long int  first_smallest_ele = q.top();
            q.pop();
            long long int  second_smallest_ele = q.top();
            q.pop();
            long long int ele_to_be_pushed = min(first_smallest_ele,second_smallest_ele)*2+max(first_smallest_ele,second_smallest_ele);
            q.push(ele_to_be_pushed);
            count_of_operations++;
        }
        return count_of_operations;

    }
};