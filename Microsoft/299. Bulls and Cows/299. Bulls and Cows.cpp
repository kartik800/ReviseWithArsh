class Solution {
public:
    string getHint(string secret, string guess) {
       int n = guess.size();
       int bulls = 0;
       int cows = 0;
       map<int,int> mp1;
       map<int,int> mp2;

       for(int i=0;i<n;i++){
           if(guess[i] == secret[i]) bulls++;
           else{
               mp1[secret[i]-'0']++;
               mp2[guess[i]-'0']++;
           }
       }

       for(auto it: mp1){
           if(mp2.find(it.first) != mp2.end()){
               cows += min(it.second, mp2[it.first]);
           }
       }

        string s="";
        s=to_string(bulls)+"A"+to_string(cows)+"B";
        return s;
    }
};