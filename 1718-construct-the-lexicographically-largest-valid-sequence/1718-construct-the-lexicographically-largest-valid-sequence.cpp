class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
    int i=0;
    int size = n;
    //n = the value that is to be filled (5 3 1 4 2 )
    vector<int>v(2*n-1,0);// total length of sequence will be 2*n-1
    while(i<2*size-1){
        // cout <<"index => "<< i << "  value of n =>" << n <<"  size of array => "<< size<<endl;
        if(v[i]!=0) i++;
        else{
            if(n<=0)  n=size-1;
            if(n==1){
                v[i++]=1;
                n = n - 1;
            }
                else{
                v[i]=n;
                v[i+n]=n;
                i++;
                n=n-2;
            }
        }
        // print_vec(v);
    }
    return v;
}
};