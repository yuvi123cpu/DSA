class Solution {
public:

    int cross(vector<int>& a, vector<int>& b, vector<int>& c)
    {
        return (b[0] - a[0])*(c[1] - a[1]) -
               (b[1] - a[1])*(c[0] - a[0]);
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {

        if(trees.size() <=3)
        return trees;

        sort(trees.begin(), trees.end());

        vector<vector<int>> h;

        for(auto x : trees)
        {
            while(h.size() >= 2 && cross(h[h.size() - 2], h.back(), x) < 0)
            h.pop_back();
            h.push_back(x);
        }
        int n = h.size();

        for(int i = trees.size() - 2;i>=0;i--)
        {
            while(h.size() > n && cross(h[h.size() -2], h.back(), trees[i]) < 0)
            h.pop_back();
            h.push_back(trees[i]);
        }
        h.pop_back();

        sort(h.begin(), h.end());

        h.erase(unique(h.begin(),h.end()), h.end());

        return h;

        
    }
};