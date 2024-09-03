class MedianFinder {
        priority_queue<int>leftside;
        priority_queue< int, vector<int> ,greater<int> >rightside ; 
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        
        if(leftside.size()==0)
        {
            leftside.push(num);
            return;
        }
        
        if(num<=leftside.top())
        {
            leftside.push(num);
        }
        else
        {
            rightside.push(num);
        }
        balanceHeaps();
    }
    void balanceHeaps()
    {
        //  minheap size (rightside)  should not be greater than maxheap size (leftside)
        if(rightside.size()>leftside.size())
        {
            leftside.push(rightside.top());
            rightside.pop();
        }
        //left and rightside me difference 1 se jyada nhi hona chahiye 
        else if (rightside.size()+1<leftside.size())
        {
            rightside.push(leftside.top());
            leftside.pop();
        }
    }
    
    double findMedian() {
        // left>right
        if(leftside.size()>rightside.size())
        return leftside.top();
        else
        {
            double ans = (leftside.top()+rightside.top());
            ans=ans/2.0;
            return ans ;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */