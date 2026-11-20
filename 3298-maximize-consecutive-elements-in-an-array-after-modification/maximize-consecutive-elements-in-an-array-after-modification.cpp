class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int maxi=0;
        int count=1;
        sort(nums.begin(),nums.end());
        // for(int i=1;i<nums.size();i++)
        // {
        //     if(nums[i]==nums[i-1])
        //     {
        //         count++;
        //         maxi=max(count,maxi);
        //     }
        //     else
        //     {
        //         count=1;
        //         maxi=max(count,maxi);
        //     }
        // }
        // return maxi;
        unordered_map<int,int>dp;
        int ans=0;
        for(int x:nums)
        {
            dp[x + 1] = dp[x] + 1;
            dp[x] = dp[x - 1] + 1;

            ans = max(ans, max(dp[x], dp[x + 1]));
        }
        return ans;
    }
};