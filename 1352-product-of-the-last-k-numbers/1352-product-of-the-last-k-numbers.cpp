class ProductOfNumbers {
public:

        vector<int>nums;
    ProductOfNumbers() {
        // stack<int>s;
    }
    
    void add(int num) {
        // s.push(num);
        nums.push_back(num);
    }
    
    int getProduct(int k) {
        long long int product=1;
        int n = nums.size();
        for(int i =n-1 ; i >= n-k ; i--)
        {
            product*=nums[i];
        }
        return product;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */