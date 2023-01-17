class Solution {
public:
    int magicalString(int n) {
        string s="";
        s+="122";
        int i=2,c=1;
        while(i<n && s.size()<n)
        {
            if(s[i]=='1')
            {
                c++;
                if(s[s.size()-1]=='2')
                s+='1';
                else
                {
                    s+='2';
                }
            }
            else
            {
                if(s[s.size()-1]=='2')
                s+="11";
                else
                {
                    s+="22";
                }
            }
            i++;
        }
        while(i<n)
        {
            if(s[i]=='1')
            c++;
            i++;
        }
        return c;
    }
};