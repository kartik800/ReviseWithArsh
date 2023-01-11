class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> availability;
        unordered_map<int,int> vacency;
        for(auto &num: nums){
            availability[num]++;
        }

        for(int &num: nums){

           if(availability[num] <= 0) continue;

           else if(vacency[num] > 0){
               availability[num]--;
               vacency[num]--;
               vacency[num+1]++;
           }
           else if(availability[num] > 0 && availability[num+1]> 0 && availability[num+2] > 0){
               availability[num]--;
               availability[num+1]--;
               availability[num+2]--;
               vacency[num+3]++;
           }
           else {
               return false;
           }
        }
        return true;
        
    }
};