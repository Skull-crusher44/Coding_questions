class Solution {
public:
    int myAtoi(string s) {
        double n=0;
        int i=0;
        while(s[i]==' ')
            i++;

        bool positive = s[i] == '+';
        bool negative = s[i] == '-';
        positive == true ? i++ : i;
        negative == true ? i++ : i;

       
            while(s[i]>='0'&&s[i]<='9'&&i<s.length())
            {
                n=10*n+(s[i++]-'0');
            }
            n=(negative==true?-n:n);
            n = (n > INT_MAX) ? INT_MAX : n;
            n = (n < INT_MIN) ? INT_MIN : n;
            return n;
        
    }
};