class Solution {
vector<int> ans;
int maxPoints = 0;
private:
    void solve(int ind, int score, int numArrows, vector<int>&aliceArrows, vector<int>&res){
        if(ind < 0 || numArrows == 0){
            if(score > maxPoints){
                maxPoints = score;
                ans = res;
            }
            return;
        }

        if(numArrows > aliceArrows[ind]){
            res[ind] = aliceArrows[ind] + 1;
            solve(ind-1,score+ind, numArrows-(aliceArrows[ind] + 1), aliceArrows, res);
            res[ind] = 0;
        }
        solve(ind-1,score, numArrows, aliceArrows, res);

    }
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> res(12,0);
        solve(11,0,numArrows, aliceArrows, res);
        // arrows left after all operation 
        int cnt=0;
        for(auto it:ans){
            cnt+=it;

        }
        int startind=numArrows-cnt;
        if(startind>0){
            ans[0]+=startind;
        }
         return ans;

        
    }
};