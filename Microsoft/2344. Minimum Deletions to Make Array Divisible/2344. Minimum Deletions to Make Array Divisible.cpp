class Solution {
private:
    int gcd(int a, int b){
        if(b==0) return a;
        return gcd(b, a%b);
    }
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        
        int n = nums.size();
        int ArrayGcd = numsDivide[0];
        for(int i=1;i<numsDivide.size();i++){
            ArrayGcd = gcd(ArrayGcd, numsDivide[i]);
        }
        sort(begin(nums), end(nums));
        int deletion = 0;
        for(int i=0;i<n;i++){
            if(ArrayGcd%nums[i] != 0) deletion++;
            else break;
        }
        return deletion == n ? -1 : deletion;
    }
};