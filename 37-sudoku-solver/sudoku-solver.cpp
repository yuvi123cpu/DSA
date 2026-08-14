class Solution {
public:

    bool solve(vector<vector<char>>& b)
    {
        for(int r = 0;r<9;r++)
        for(int c = 0;c<9;c++)
        if(b[r][c] == '.')
        {
            for(char x = '1'; x<='9';x++)
            {
                bool ok = true;

                for(int i = 0;i<9;i++)
                if(b[r][i] == x || b[i][c] == x)
                ok = false;
                
               for(int i = r/3*3;i<r/3*3+3;i++)
               for(int j = c/3*3;j<c/3*3+3;j++)
               if(b[i][j] == x)
               ok = false;

               if(ok)
               {
                b[r][c] = x;
                if(solve(b))
                return true;
                b[r][c] = '.';
               }

            }
            return false;
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& b) {
        solve(b);
    }
};