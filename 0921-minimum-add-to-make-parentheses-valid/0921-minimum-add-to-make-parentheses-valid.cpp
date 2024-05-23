class Solution {
public:
    int minAddToMakeValid(string s) {

  stack<char>st;
  for(int i=0;i<s.length();i++)
  {
    char ch= s[i];
    if(ch=='(')                         //if ch ='(' then push ch into stack  & wait for closing braces ')'
      st.push(ch);
    else
    {
      if(!st.empty()&&st.top()=='(')     // if i get ')' then first check wheter stack is empty or not 
        st.pop();                        //then i will check whether top element is '(' or not  (string ="(())") 
        else
        st.push(ch);                       // if ch= ')'===> either top is ')' or stack is empty ==> then push ')'
    }                                      // string =" ))()()"or"(())))"
  }
//   int a=0,b=0;
//   while(!st.empty())
//   {
    
//     char ch = st.top();
//     if(ch=='(')
//     a++;
//     else
//     b++;
//     st.pop();
//   }
//   int ans = a+b;
  return st.size();


        
    }
};