class Solution {
private:
    int reverseNumber(int n){
        int reversedNum = 0;
        int remainder;
        while(n > 0){
            int remainder = n%10;
            reversedNum = reversedNum * 10 + remainder;
            n/=10;
        }
        return reversedNum;
    }
public:
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        int mod = (int)1e9+7;
        unordered_map<int,int> mp;
        int cnt =0;
        for(int i=0;i<n;i++){
            int temp = nums[i] - reverseNumber(nums[i]);
            mp[temp]++;
            cnt = (cnt + mp[temp]-1)%mod;

        }
        return cnt%mod;

    }
};