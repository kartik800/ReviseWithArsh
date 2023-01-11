class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            map<int,int> mp;
            for(int j=0;j<n;j++){
                if(i != j){
                    int dis = (points[i][0] - points[j][0])*(points[i][0] - points[j][0]) + (points[i][1] - points[j][1])*(points[i][1] - points[j][1]);
                    mp[dis]++;
                }
            }
            for(auto &it: mp){
                if(it.second >= 2) cnt += (it.second)*(it.second -1);
            }
        }
        return cnt;
        
    }
};