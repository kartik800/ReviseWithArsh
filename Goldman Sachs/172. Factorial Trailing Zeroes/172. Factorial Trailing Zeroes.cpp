class Solution {
public:
    int trailingZeroes(int n) {
        int num_zeroes = 0;
        for(int i=5;i<=n;i+=5){
            int num = i;
            while(num%5==0){
                num /= 5;
                num_zeroes++;
            }
        }
        return num_zeroes;
    }
};