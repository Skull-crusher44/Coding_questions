class Solution {
public:
    int characterReplacement(string s, int k) {

        int count_diff=0;
        int left=0,right=0,max_len=0;
        while(right<s.size()){
            if(s[right]!=s[left])
                count_diff++;
            while(count_diff > k)// reset the window so that it must contain k flips(for flip) by shifting the left pointer 
            {
                if(s[left]!=s[left+1])
                count_diff--;
                left++;
            }
            max_len=max(max_len,right-left+1);
            right++;
        }
        return max_len;
    }
};