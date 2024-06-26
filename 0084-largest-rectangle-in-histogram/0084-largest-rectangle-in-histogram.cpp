// class Solution {
// private:
// //solution 1 Love Babbar 
//     vector<int> nextSmallerElement(vector<int> arr, int n) {
//         stack<int> s;
//         s.push(-1);
//         vector<int> ans(n);

//         for(int i=n-1; i>=0 ; i--) {
//             int curr = arr[i];
//             while(s.top() != -1 && arr[s.top()] >= curr)
//             {
//                 s.pop();
//             }
//             //ans is stack ka top
//             ans[i] = s.top();
//             s.push(i);
//         }
//         return ans;
//     }
    
//     vector<int> prevSmallerElement(vector<int> arr, int n) {
//         stack<int> s;
//         s.push(-1);
//         vector<int> ans(n);

//         for(int i=0; i<n; i++) {
//             int curr = arr[i];
//             while(s.top() != -1 && arr[s.top()] >= curr)
//             {
//                 s.pop();
//             }
//             //ans is stack ka top
//             ans[i] = s.top();
//             s.push(i);
//         }
//         return ans; 
//     }
    
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n= heights.size();
        
//         vector<int> next(n);
//         next = nextSmallerElement(heights, n);
            
//         vector<int> prev(n);
//         prev = prevSmallerElement(heights, n);
        
//         int area = INT_MIN;
//         for(int i=0; i<n; i++) {
//             int l = heights[i];
            
//             if(next[i] == -1) {
//                 next[i] = n;
//             }
//              int b = next[i] - prev[i] - 1;
//             int newArea = l*b;
//             area = max(area, newArea);
//         }
//         return area;
//     }
// };
// class Solution {
// private:
// //solution 2 coder army
//     vector<int> nextSmallerElement(vector<int> arr, int n) {
//         stack<int>s;
//         vector<int>ans(n,-1);
//         for(int i=0;i<n;i++)
//         {
//             while(!s.empty()&&arr[i]<arr[s.top()])
//             {
//                 ans[s.top()]=i;
//                 s.pop();
//             }
//             s.push(i);
//         }
//         // while(!s.empty())
//         // {
//         //     ans[s.top()]=arr.size();
//         //     s.pop();
//         // }
//         return ans;
//     }
    
//     vector<int> prevSmallerElement(vector<int> arr, int n) {
//         stack<int> s;
//         vector<int> ans(n,-1);
//         for(int i=n-1;i>=0;i--)
//         {
//             while(!s.empty()&&arr[i]<arr[s.top()])
//             {
//                 ans[s.top()]=i;
//                 s.pop();
//             }
//             s.push(i);
//         }
//         // while(!s.empty())
//         // {
//         //     ans[s.top()]=-1;
//         //     s.pop();
//         // }
//         return ans;
    
//     }
    
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n= heights.size();
        
//         vector<int> next(n);
//         next = nextSmallerElement(heights, n);
            
//         vector<int> prev(n);
//         prev = prevSmallerElement(heights, n);
        
//         int area = INT_MIN;
//         for(int i=0; i<n; i++) {
//             int l = heights[i];
            
//             if(next[i] == -1) {
//                 next[i] = n;
//             }
//              int b = next[i] - prev[i] - 1;
//             int newArea = l*b;
//             area = max(area, newArea);
//         }
//         return area;
//     }
// };

class Solution {
private:
//solution 3 optimized approach in one pass
    
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>s;
        int ans=0;
        for(int i=0;i<heights.size();i++)
        {
            while(!s.empty()&&heights[s.top()]>heights[i])
            {
                int next_small=i;
                int height=heights[s.top()];
                s.pop();
                int area;
                if(s.empty())
                {
                    area= height*(next_small);
                }
                else
                {
                int prev_small=s.top();
                area=height*(next_small-prev_small-1);
                }
                ans=max(ans,area);
            }
            s.push(i);
        }
            while(!s.empty())
            {
                int next_small=heights.size();
                int height=heights[s.top()];
                s.pop();
                int area;
                if(s.empty())
                {
                    area= height*(next_small);
                }
                else
                {
                int prev_small=s.top();
                 area=height*(next_small-prev_small-1);
                }
                ans=max(ans,area);
            }       
        
        return ans;
    }   
};