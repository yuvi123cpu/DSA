class Solution {
public:
    vector<vector<string>> ans;
    bool ispal(string s, int i, int j)
    {
        while(i < j)
        {
            if(s[i++] != s[j--])
            return false;
        }
        return true;
    }

    void solve(string s, int start, vector<string>& path)
    {
        if(start == s.size())
        {
            ans.push_back(path);
            return;

        }

        for(int end = start;end<s.size();end++)
        {
            if(ispal(s,start,end))
            {
                path.push_back(s.substr(start,end-start+1));
                solve(s,end+1,path);
                path.pop_back();
            }
        }
    }
    
    
        vector<vector<string>> partition(string s) {
            vector<string> path;
            solve(s,0,path);
            return ans;
        
    }
};