class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        long long prefix=0;
        int count=0;
        unordered_map<long long,int>mp;
        mp[0]=1;
        for( int i=0;i<nums.size();i++)
        {
            prefix+=nums[i];

            int need=prefix-goal;

            if(mp.find(need)!=mp.end())
            {
                count+=mp[need];
            }
            mp[prefix]++;
        }
       return count; 
    }
};