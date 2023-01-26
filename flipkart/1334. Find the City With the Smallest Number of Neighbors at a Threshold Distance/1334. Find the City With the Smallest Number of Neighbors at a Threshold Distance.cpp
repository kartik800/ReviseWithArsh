class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> dist(n,vector<int> (n,1e9));
        
        // diagonal element as 0 because it's a self node 
        //and distance from i to i is 0 
        for(int i=0;i<n;i++) dist[i][i] = 0;
        
        // store the distance of direct node
        for(auto it:edges){
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }
        
        // floyd warshall
        for(int k=0;k<n;k++){ // pivot node or level node 
            
            for(int i=0;i<n;i++){
                
                for(int j=0;j<n;j++){
                    
                    if(dist[i][k] != 1e9 && dist[k][j] != 1e9 && dist[i][k] + dist[k][j] < dist[i][j]){
                        
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        int citycnt;
        int ans;
        for(int i=0;i<n;i++){
            int cnt =0;
            for(int j=0;j<n;j++){
                if(i != j && dist[i][j] <= distanceThreshold) cnt++;
            }
            if(cnt <= citycnt){
                ans = i;
                citycnt = cnt;
            }
        }
        return ans;
        
    }
};