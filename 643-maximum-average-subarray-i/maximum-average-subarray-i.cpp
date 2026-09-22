class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0;
        double t=0;
        double maxi=INT_MIN;
        for(int i=0;i<k;i++)
        {
             sum=sum+nums[i];
        }
        t=sum/k;
        maxi=max(t,maxi);

        int left=0;
        int right=k;
        while(right<nums.size())
        {
            sum=sum-nums[left];
            sum=sum+nums[right];
            t=sum/k;
            maxi=max(t,maxi);
            left++;
            right++;
        }
       return maxi;    
    }
};