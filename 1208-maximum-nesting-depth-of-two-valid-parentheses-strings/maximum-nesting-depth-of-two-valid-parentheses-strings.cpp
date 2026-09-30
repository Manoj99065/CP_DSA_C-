// class Solution {
// public:
//     vector<int> maxDepthAfterSplit(string seq) {
//         stack<int>st;
//         int count=0;
//         vector<int>ans(seq.size(),0);
//         for(int i=0;i<seq.size();i++)
//         {
//             if(seq[i]=='(')
//             {
//                 st.push(i);
//                 count++;
//             }
//             else
//             {
//                  count--;
//                  ans[st.top()]=count;
//                  ans[i]=count;
//                  st.pop();
                
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int>ans(seq.size(),0);
        int depth=0;
        for(int i=0;i<seq.size();i++)
        {
            if(seq[i]=='(')
            {
                depth++;
                ans[i]=depth%2;
            }
            else
            {
                ans[i]=depth%2;
                depth--;
            }
        }
     return ans;
    }
};