class Solution {
private:
    bool check(int x, vector<vector<int>>&statements){
        int n = statements.size();
        for(int i=0;i<n;i++){
            // checking combination from (0 -> 2^n-1)
            // x = 2 and i = 0,1,2,3,.... 2^n-1;
            // 0 1 0 & 0 0 0 // false 
            // 0 1 0 & 0 0 1 // false
            // 0 1 0 & 0 1 0 // true
            // . . .   . . .
            // . . .   . . .
            if((1<<i)&x){ // if true then check what ith person says about jth person
                for(int j=0;j<n;j++){

                    if(i==j) continue; // a person can't say about itself

                    // check if any contradiction or not, if it is then return false;
                    if(statements[i][j] == 0 && ((1<<j)&x) || statements[i][j] == 1 && !((1<<j)&x)) return false;
                }
            }
        }
        return true;
    }
public:
    int maximumGood(vector<vector<int>>& statements) {
        int ans = 0;
        int n = statements.size();

        for(int i=0; i < (1 << n); i++){

            if(check(i, statements)){
                // 1 indicate good person 
                // 0 indicate bad person 
                // so we calculate number of ones which is good person
                ans = max(ans, __builtin_popcount(i));
            }
        }
        return ans;
        
    }
};