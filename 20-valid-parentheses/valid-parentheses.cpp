class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int size=s.size();
        for(int i=0;i<size;i++)
        {
            if(s[i]=='{'|| s[i]=='('|| s[i]=='[')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty())
                {
                    return false;
                }
                // cout<<s[i]<<" "<<st.top();
                if(s[i]==')'&& st.top()=='(')
                { 
                    st.pop();
                }
                else if(s[i]==']' && st.top()=='[')
                { 
                    st.pop();
                }
                else if(s[i]=='}' && st.top()=='{')
                { 
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
    if(st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
    }
};