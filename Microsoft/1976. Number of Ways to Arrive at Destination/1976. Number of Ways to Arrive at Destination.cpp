#define ll long long
class Solution {
public:
    int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        
        // Adjacency List 
        vector<pair<ll,ll>> adj[n];
        for(auto it: roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
        vector<ll> dist(n,LONG_MAX);
        dist[0] = 0;
        vector<ll> ways(n);
        ways[0] = 1;
        pq.push({0,0}); // {time, src}
        
        while(!pq.empty()){
            ll time = pq.top().first;
            ll node = pq.top().second;
            pq.pop();
            if(time > dist[node]) continue;
            for(auto it: adj[node]){
                ll v = it.first;
                ll ntime = it.second;
                
                if(time + ntime < dist[v]){
                    dist[v] = time + ntime;
                    ways[v] = ways[node];
                    pq.push({dist[v], v});
                }
                else if(time + ntime == dist[v]){
                    ways[v] = (ways[v] + ways[node])%mod;
                }
                
            }
        }
        for(int i=0;i<n;i++){
            cout<<dist[i]<<" ";
            
           
        }
        cout<<endl;
        for(int i=0;i<n;i++){
             cout<<ways[i]<<" ";
           
        }
        return ways[n-1];
        
        
    }
};