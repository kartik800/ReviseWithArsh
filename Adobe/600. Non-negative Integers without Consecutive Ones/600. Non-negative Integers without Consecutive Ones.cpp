class Solution {
public:
    int findIntegers(int n) {
        vector<int> fib(31);
        
        fib[0] = 1; // 0 
        fib[1] = 2; // 0 or 1 bit

        // counting number of non-negative integer without consecutive one
        for(int i=2;i<30;i++){
            fib[i] = fib[i-1] + fib[i-2];
        }

        int ans = 0, bit = 30, prev_bit_one = 0;

        while(bit >= 0){

            // check if most significant bit is set or not
            if(n & (1 << bit)){
                ans += fib[bit];
                // if prev_bit_one is set then there is consecutive prefix we can't append 
                // 180 -> 10110100
                     //   1 -> 0000000 - 1111111  ans += fib[7];
                     //   101 -> 00000 - 11111 ans += fib[5];
                     //   1011 (two consecutive set bit ) return ans;
                if(prev_bit_one) return ans;
                prev_bit_one = 1;
            }else{
                prev_bit_one = 0;
            }
            bit--;

        }
        return ans+1;  // +1 for itself bit
    }
};