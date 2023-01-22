class Solution {
public:
    int solve(vector<int>& price, vector<vector<int>>& special, vector<int> needs, int index){
        if(index==special.size()){
            //Buy everything at the normal price
            int res = 0;
            for(int i=0;i<needs.size();i++){
                res += needs[i] * price[i];
            }
            return res;
        }
        
        //Reject Offer
        int reject = solve(price, special, needs, index + 1);
        
        //Apply Offer 
        for(int i=0;i<needs.size();i++){
            needs[i] = needs[i] - special[index][i]; //Decrement the needs
            if(needs[i] < 0) return reject; //Can't use this offer
        }
        
        int accept = special[index][needs.size()] + solve(price, special, needs, index);
        
        return min(accept, reject);
    }
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return solve(price, special, needs, 0);
    }
};