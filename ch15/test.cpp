#include <vector>
using std::vector;


class Solution {
    int dx[4]{0, -1, 1, 0}, dy[4]{1, 0, 0, -1};
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size(), ans = 0;
        if(row == 0) return 0;
        int col = grid[0].size();
        vector<vector<bool>> vis(row, vector<bool>(col, false));
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                if(grid[i][j] == 1)
                {
                    ans += 4;
                    for(int k = 0; k < 4; ++k)
                    {
                        int newI = i + dx[k], newJ = j + dy[k];
                        if(newI >= 0 && newI < row && newJ >= 0 && newJ < col && grid[newI][newJ])
                        {
                            --ans;
                            if(!vis[newI][newJ]) vis[newI][newJ] = true;
                        }
                    }
                }
            }
        }
        return ans;
    }
};