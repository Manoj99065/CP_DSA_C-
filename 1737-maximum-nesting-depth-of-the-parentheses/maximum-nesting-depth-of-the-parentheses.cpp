class Solution {
public:
    int maxDepth(string s) {
        stack<int>st;
        int count=0;
        int maxi=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
            count=count+1;
            st.push(count);
            maxi=max(st.top(),maxi);
            }
            else if(s[i]==')')
            {
                st.pop();
                count=count-1;
            }
            else
            {
                continue;
            }   
        }
       return maxi; 
    }
};