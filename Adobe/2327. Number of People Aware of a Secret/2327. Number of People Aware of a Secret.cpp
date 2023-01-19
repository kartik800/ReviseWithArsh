class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long> dp(n+1);
        int mod = (int)1e9 + 7;
        int noOfSharingPeople = 0;
        int ans = 0;

        dp[1] = 1; // first day only one person knows 

        for(int i=2; i<=n;i++){

            noOfSharingPeople = (noOfSharingPeople + dp[max(i-delay, 0)] - dp[max(i-forget, 0)] + mod) % mod;

            dp[i] = noOfSharingPeople;
        }
        for(int i= n-forget+1; i <= n;i++){
            ans = (ans +dp[i]) %mod;
        }
        return ans;

        
    }
};