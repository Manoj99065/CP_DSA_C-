// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int left=0;
//         int right=left+1;
//         int ans=0;
//         while(left<s.size())
//         {
//             int count=1;
//             int j=0;
//             while(right < s.size() && j < k || s[right] == s[left])
//             {
//                 if(s[right] != s[left] && j < k)
//                 {
//                     j++;
//                 }
//             right++;
//             count++;
//             }
//             ans=max(count,ans);
//             left++;
//         }
//       return ans;  
//     }
// };

// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int left = 0;
//         int ans = 0;

//         while(left < s.size())
//         {
//             int right = left + 1;
//             int count = 1;
//             int j = 0;

//             while(right < s.size() && (j < k || s[right] == s[left]))
//             {
//                 if(s[right] != s[left] && j < k)
//                 {
//                     j++;
//                 }

//                 right++;
//                 count++;
//             }

//             ans = max(count, ans);
//             left++;
//         }

//         return ans;
//     }
// };


class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        int maxdiff=0;
        int result=0;
        vector<int>ans(26,0);
        for(int right=0;right<s.size();right++)
        {
            int change=0;
            ans[s[right]-'A']++;
            maxdiff=max(maxdiff,ans[s[right]-'A']);  
            change=(right-left+1)-maxdiff;
            while(change>k)
            {
                ans[s[left]-'A']--;
                left++;
                change=(right-left+1)-maxdiff;
            }
           result=max(result,(right-left+1)); 
        }
    return result;
    }
};