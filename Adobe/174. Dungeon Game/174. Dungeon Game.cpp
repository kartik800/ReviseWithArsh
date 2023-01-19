class Solution {
private:
    int solve(int i, int j, vector<vector<int>>&dungeon,  vector<vector<int>> &dp){
        int n = dungeon.size();
        int m =  dungeon[0].size();

        if(i == n || j == m) return 1e9;

        if(i == n-1 && j == m-1) return  (dungeon[i][j] <= 0) ? -dungeon[i][j] + 1 : 1;
        
        if(dp[i][j] != 1e9) return dp[i][j];

        int health = min(solve(i+1, j, dungeon,dp), solve(i, j+1, dungeon,dp));

        int res = 0;
        if(health - dungeon[i][j] > 0) res = health - dungeon[i][j];
        else res = 1;
        return dp[i][j] = res;
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<int>> dp(dungeon.size(), vector<int>(dungeon[0].size(), 1e9));
        return solve(0,0,dungeon,dp);
    }
};