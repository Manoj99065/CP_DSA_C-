class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
      set<int>st;
      long long ans=0;
      long long sum=0;
      int left=0;
      for(int r=0;r<nums.size();r++)
      {
        while(st.find(nums[r])!=st.end())
        {
         st.erase(nums[left]);
         sum-=nums[left];
         left++;
        } 

       st.insert(nums[r]);
       sum += nums[r];
     if(r-left+1>k)
      {
        st.erase(nums[left]);
        sum-=nums[left];
        left++;
      }
      if(r-left+1==k)
      {
        ans=max(ans,sum);
      } 
      }
      return ans;
    }
};