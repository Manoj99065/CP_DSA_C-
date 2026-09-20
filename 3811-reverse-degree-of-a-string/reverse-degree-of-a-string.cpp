class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        int count=1;
        for(int i=0;i<s.length();i++)
        {
        int c='a'-s[i];
        cout<<c;
        int k=26+c;
       
        sum=sum+(k*count);
        count++;
        }
        return sum;
        
    }
};