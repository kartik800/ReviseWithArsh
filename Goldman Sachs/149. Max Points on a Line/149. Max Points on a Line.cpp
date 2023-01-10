class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1) return 1;
        int result = 0;
        for(int i=0;i<n;i++){ // p1 {x1,y1}

            for(int j=i+1;j<n;j++){ //p2 {x2,y2}
                int count = 2;
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                for(int k=0;k<n;k++){ // p3 {x3,y3}
                    if(i != k && j != k){
                        int dx_ = points[k][0] - points[i][0];
                        int dy_ = points[k][1] - points[i][1];

                        if(dy*dx_ == dy_*dx){
                            count++;
                        }
                    }
                }
                result = max(result, count);
            }
        }
        return result;
    }
};


// optimal Approach
// class Solution {
// public:
//     int maxPoints(vector<vector<int>>& points) {
//         int n= points.size();
//         if(n == 1) return 1;
//         int result = 0;
//         for(int i=0;i<n;i++){
//             unordered_map<double,int> mp;
//             for(int j=0;j<n;j++){
//                 if(j == i) continue;
//                 int dy = points[j][1] - points[i][1];
//                 int dx = points[j][0] - points[i][0];
//                 double thetha = atan2(dy,dx);
//                 mp[thetha]++;
//             }
//             for(auto &it: mp){
//             result = max(result, it.second + 1);
//             }
//         }

        
//         return result;

        
//     }
// };