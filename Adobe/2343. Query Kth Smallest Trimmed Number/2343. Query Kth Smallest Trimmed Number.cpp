class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int q = queries.size();
        int n = nums.size();

        for(vector<int> querie: queries){
            int k = querie[0];
            int trim = querie[1];
            priority_queue<pair<string, int>> pq;
            for(int i=0;i<n;i++){
                string val = nums[i];
                if(trim < nums[i].size()) val = nums[i].substr(nums[i].size()-trim, trim);

                pair<string, int> val1 = {val, i};
                if(pq.size() < k){
                    pq.push(val1);
                }else{
                    if(val1 < pq.top()){
                        pq.pop();
                        pq.push(val1);
                    }
                }
            }
            ans.push_back(pq.top().second);
        }
        return ans;
    }
};