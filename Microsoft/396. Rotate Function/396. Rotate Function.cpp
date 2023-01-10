class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {

        int sum = 0;
        int f = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            f += i*nums[i];
        }
        int mx = f;
        for(int i=nums.size()-1;i>0;i--){
            int tot = f + sum - (nums.size()* nums[i]);
            mx = max(mx, tot);
            f = f + sum - (nums.size()*nums[i]);
        }
        return mx;
    }
};