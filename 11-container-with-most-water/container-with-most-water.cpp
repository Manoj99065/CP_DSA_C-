class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int left=0;
        int right=height.size()-1;
        int ans=0;
        while(left<right)
        {
          int k= min(height[left],height[right]);
          int arr=k*(right-left);
          ans=max(ans,arr);
          if(height[left]<height[right])
          {
            left++;
          }
          else
          { 
            right--;
          }
        }
      return ans;  
    }
};