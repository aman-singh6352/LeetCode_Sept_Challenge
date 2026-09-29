class Solution {
    public:
        bool solve(int i, int j, int open, vector<vector<char>>& grid, vector<vector<vector<int>>>& dp){
            if(i < 0 || j < 0) {
                return false;
            }
            if(grid[i][j] == '(') {
                if(open == 0) return false;
                open--;
            }
            else open++;
            if(open > i+j) return false;
            if(i == 0 && j == 0) {
                return open == 0;
            }
            if(dp[i][j][open] != -1) return dp[i][j][open];
    
            bool ans = solve(i, j-1, open, grid, dp) || solve(i-1, j, open, grid, dp);
            return dp[i][j][open] = ans;
        }
        bool hasValidPath(vector<vector<char>>& grid) {
            int n = grid.size(), m = grid[0].size();
            vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(n + m, -1)));
            return solve(n-1, m-1, 0, grid, dp);
        }
    };

/* ----------------------------------------------------- JAVA CODE ----------------------------------------------------------*/
class Solution {
    private boolean solve(int i, int j, int open, char[][] grid, int[][][] dp){
        if(i < 0 || j < 0) {
            return false;
        }
        if(grid[i][j] == '(') {
            if(open == 0) return false;
            open--;
        }
        else open++;
        if(open > i+j) return false;
        if(i == 0 && j == 0) {
            return open == 0;
        }
        if(dp[i][j][open] != -1) return dp[i][j][open] == 1;

        boolean ans = solve(i, j-1, open, grid, dp) || solve(i-1, j, open, grid, dp);
        dp[i][j][open] = (ans ? 1 : 0);
        return ans;
    }
    public boolean hasValidPath(char[][] grid) {
        int n = grid.length, m = grid[0].length;
        int[][][] dp = new int[n][m][n+m];
        for(int[][] first:dp){
            for(int[] second:first){
                Arrays.fill(second, -1);
            }
        }
        return solve(n-1, m-1, 0, grid, dp);
    }
}