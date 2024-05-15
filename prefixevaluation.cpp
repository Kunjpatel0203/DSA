// Online C++ compiler to run C++ program online
#include <iostream>
#include<stack>
#include<math.h>
using namespace std;
int prefix(string s)
{int i;
    stack<int> st;
    for( i=s.length()-1;i>=0;i--)
    {
        if(s[i]>='0' && s[i]<='9')
        {st.push(s[i]-'0');}
        else
        {
            int op1=st.top();
            st.pop();
            int op2=st.top();
            st.pop();
            
            switch(s[i])
            {
                case '+':
                st.push(op1+op2);
                break;
                case '-':
                st.push(op1-op2);
                break;
                case '/':
                st.push(op1/op2);
                break;
                case '*':
                st.push(op1/op2);
                break;
                
                }
        }
    }
    return st.top();
}
int main() {
    // Write C++ code here
    // << "Hello world!";

cout<<prefix("-+7*45+20");

    return 0;
}