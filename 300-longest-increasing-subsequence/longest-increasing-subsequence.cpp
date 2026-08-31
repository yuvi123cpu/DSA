class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;

        for(int x : nums)
        {
            auto i = lower_bound(lis.begin(),lis.end(), x);

            if(i == lis.end())
            lis.push_back(x);

            else
            *i = x;
        }

        return lis.size();
        
    }
};