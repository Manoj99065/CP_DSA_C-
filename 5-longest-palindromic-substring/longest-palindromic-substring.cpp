class Solution {
public:
    string longestPalindrome(string s) {
        string ans="";
        if(s.size()==1)
        {
            ans=ans+s[0];
            return ans;
        }
        if(s.size()==0)
        {
            return "";
        }
        for(int i=0;i<s.size()-1;i++)
        {
           
            for(int j=i;j<s.size();j++)
            {
                int left=i;
                int right=j;
                bool check=false;
                while(left<=right)
                {
                  
                    if(s[left]!=s[right])
                    {
                        check=true;
                       
                         break;
                    }
                    left++;
                    right--;
                    
                }
                
                if(!check && j-i+1>ans.size() )
                {
                   string M="";
                   for(int x=i;x<=j;x++)
                   {
                       M=M+s[x];
                   } 
                ans=M;
                }
            }
        }
        
     return ans;   
    }
};