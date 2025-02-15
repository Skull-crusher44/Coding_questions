class Solution {
public:
    bool check_for_punishment(int sum,string no)
    {
        if(sum==stoi(no))return true;
        if(sum>stoi(no))return false;
        bool result = false;
        for(int i =1 ; i < no.length() ; i++)
        {
            int new_sum = sum - stoi(no.substr(0,i));
            string new_no = no.substr(i);
            result= result||check_for_punishment(new_sum,new_no);
        }
        return result;
    }
    int punishmentNumber(int n) {
        string s = to_string(n);
        long long int sum=0;
        for(int i =1 ; i <= n ; i++)
        {
            if(check_for_punishment(i,to_string(i*i)))
            {
                sum+=i*i;
            }
        }
        return sum;
    }
};