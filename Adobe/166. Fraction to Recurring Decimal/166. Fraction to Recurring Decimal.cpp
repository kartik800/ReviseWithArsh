class Solution {
public:
    string fractionToDecimal(int num, int deno) {
        string ans = "";
        if ((num<0 && deno>0) || (num>0 && deno<0)) ans += "-";
        num = abs(num);
        deno = abs(deno);
        long long q = num/deno;
        long long r = num % deno;
        ans += to_string(q);
        if(r == 0) return ans;
        else {
            ans += ".";
            unordered_map<int,int> mp;

            while(r != 0){
                if(mp.find(r) != mp.end()){
                    int len = mp[r];
                    ans.insert(len, "(");
                    ans += ")";
                    break;

                }
                else{
                mp[r] = ans.size();
                r *= 10;
                q = r/deno;
                r = r % deno;
                ans += to_string(q);
                }

            }
        }
        return ans;
        
    }
};