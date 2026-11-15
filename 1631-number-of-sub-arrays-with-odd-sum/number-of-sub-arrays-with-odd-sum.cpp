class Solution {
public:
    const int MOD=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        long long ans=0;
        long long sum=0;
        long long even=1;
        long long odd=0;
        for(int num : arr)
        {
            sum+=num;
            if(sum%2==0)
            {
                ans=(ans+odd)%MOD;
                even++;
            }
            else
            {
                ans=(ans+even)%MOD;
                odd++;
            }

        }
        return ans;
        
        
    }
};