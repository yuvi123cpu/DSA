class Solution {
public:

      int empty = 0, ans = 0;

      void dfs(vector<vector<int>>& grid, int r, int c, int count)
      {
        int  m = grid.size();
        int n = grid[0].size();

        if(r < 0 || c < 0 || r>=m || c >=n || grid[r][c] == -1)
        return;

        if(grid[r][c] == 2)
        {
            if(count == empty)
            {
                ans++;
                return;
            }
        }

        int temp = grid[r][c];

        grid[r][c] = -1;

        dfs(grid,r+1,c,count+1);
        dfs(grid,r-1,c,count+1);
        dfs(grid,r,c+1,count+1);
        dfs(grid,r,c-1,count+1);

        grid[r][c] = temp;


      }


    int uniquePathsIII(vector<vector<int>>& grid) {
        int a,b;
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 0)
                empty++;

                else if(grid[i][j] == 1)
                {
                    a = i;
                    b = j;
                }

            }
        }

        empty++;

        dfs(grid,a,b,0);

        return ans;
        
    }
};