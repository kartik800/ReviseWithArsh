class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        int mn = INT_MAX;
        int mx = INT_MIN;
        if(n==1) return 0;
        for(int i=0;i<n;i++){

            if(i==0){
                if(nums[i] > nums[i+1]){
                    mn = min(mn, nums[i]);
                    mx = max(mx, nums[i]);
                }
            }
            else if(i == n-1){
                if(nums[i] < nums[i-1]){
                    mn = min(mn, nums[i]);
                    mx = max(mx, nums[i]);
                }
            }
            else {
                if(nums[i] > nums[i+1] || nums[i] < nums[i-1]){
                mn = min(mn, nums[i]);
                mx = max(mx, nums[i]);
                }
            }
        }
        if(mn == INT_MAX && mx == INT_MIN) return 0;

        // find poisition of max and min;
        int i,j;
        for(i=0;i<n && nums[i] <= mn; i++);
        for(j=n-1; j>=0 && nums[j] >= mx;j--);

        return j-i+1;
        
    }
};