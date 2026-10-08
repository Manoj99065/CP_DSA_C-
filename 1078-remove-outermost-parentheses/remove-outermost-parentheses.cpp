class Solution {
public:
    string removeOuterParentheses(string s) {
        // stack<char>st;
        int ans=0;
        string ans1="";
        for(char c:s)
        {
            if(c=='(')
            {
                if(ans>0)
                {
                    ans1+=c;
                }
                ans++;
            }
            else
            {
                if(ans>1)
                {
                    ans1+=c;
                }
                ans--;
            }
        }
        return ans1;
    }
};