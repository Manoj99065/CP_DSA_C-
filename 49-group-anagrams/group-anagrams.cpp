class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(string s1:strs)
        {
            
                string s2=s1;
                sort(s2.begin(),s2.end());
                mp[s2].push_back(s1); 
        }
        vector<vector<string>>ans;
        for(auto &x:mp)
        {
            vector<string>ans1;
            for(auto&y:x.second)
            {
              ans1.push_back(y);
            }
            ans.push_back(ans1);
        }
    return ans;  
    }
};