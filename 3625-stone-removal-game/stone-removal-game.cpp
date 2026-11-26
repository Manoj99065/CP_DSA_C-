class Solution {
public:
    bool canAliceWin(int n) {
        int k=10;
        int i=0;
        while(n>=k)
        {
            n=n-k;
            k--;
            i= !i;

        }
        if(i==1)
        {
            return true;
        }
        return false;        
    }
};