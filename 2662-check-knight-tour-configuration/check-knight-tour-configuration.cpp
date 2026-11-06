class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int r, int c, int n, int expVal) {

        if(r < 0 || c < 0 || r >= n || c >= n ||
           grid[r][c] != expVal)
            return false;

        if(expVal == n*n - 1)
            return true;

        return
            isValid(grid, r-2, c+1, n, expVal+1) ||
            isValid(grid, r-1, c+2, n, expVal+1) ||
            isValid(grid, r+1, c+2, n, expVal+1) ||
            isValid(grid, r+2, c+1, n, expVal+1) ||
            isValid(grid, r+2, c-1, n, expVal+1) ||
            isValid(grid, r+1, c-2, n, expVal+1) ||
            isValid(grid, r-1, c-2, n, expVal+1) ||
            isValid(grid, r-2, c-1, n, expVal+1);
    }

    bool checkValidGrid(vector<vector<int>>& grid) {

        if(grid[0][0] != 0)
            return false;

        return isValid(grid, 0, 0, grid.size(), 0);
    }
};