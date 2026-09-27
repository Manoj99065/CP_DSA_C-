class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>ans(26,0);
        if(s.size()!=t.size())
        {
            return false;
        }
        for(int i=0;i<s.size();i++)
        {
               int j=(s[i]-'a');
               ans[j]++;
        }
          for(int i=0;i<t.size();i++)
        {
               int j=(t[i]-'a');
               ans[j]--;
        }
        for(int x:ans)
        {
            if(x!=0)
            {
                return false;
            }
        }
        return true;
    }
};