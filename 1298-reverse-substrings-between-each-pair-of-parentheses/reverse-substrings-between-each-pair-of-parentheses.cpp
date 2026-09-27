// class Solution {
// public:
//     string ans="";
//     void swap(string &ans)
//     {
//         int left=0;
//         int right=ans.size()-1;
//         while(left<=right)
//         {
//             std::swap(ans[left],ans[right]);
//             left++;
//             right--;
//         }
//     }
//     string reverseParentheses(string s) {
//         stack<int>st;
//         int left=0;
//         int right=s.size()-1;
        
//         int count=1;
//         for(int i=0;i<s.size();i++)
//         {
//             if(s[i]=='(')
//             {
//                 st.push(i);
                
//             }
//             else if(s[i]==')')
//             {
//                 if(i<=right)
//                 {
//                     left=st.top();
//                     for(int j=left+1;j<i;j++)
//                     {
//                         ans = ans + s[j];
//                     }
                   
//                     st.pop();
//                     right=i;
//                     swap(ans);   
//                 }

//                 else if(i>right)
//                 {
//                     for(int x=left+1;x<right;x++)
//                     {
//                         ans=s[x]+ans;
//                     }
//                     for(int y=right+1;y<i;y++)
//                     {
//                         ans=ans+s[y];
//                     }
//                     left=st.top();
//                     st.pop();
//                     right=i;
//                     swap(ans);
//                 }
//             }
//         }
//      return ans;   
//     }
// };

class Solution {
public:
     string reverseParentheses(string s) {
        stack<string>st;
        string curr="";
        for(char x:s)
        {
            if(x=='(')
            {
                 st.push(curr);
                 curr="";
            }
            else if(x==')')
            {
                reverse(curr.begin(),curr.end());
                curr=st.top()+curr;
                st.pop();
            }
            else
            {
                curr=curr+x;
            }
        }
        return curr;
     }
};
 