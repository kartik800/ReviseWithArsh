class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        int l=0;
        int r = 0;
        int end = n-1;
        unordered_map<char, int> mp;
        int count = 0;
        while(r < n){
            mp[s[r]]++;

            while(mp['a'] >= 1 && mp['b'] >= 1 && mp['c'] >= 1){
                count += 1 + (end -r);

                mp[s[l]]--;
                l++;
            }
            r++;

        }
        return count;
        
    }
};