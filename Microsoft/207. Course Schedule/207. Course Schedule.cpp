class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses];
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        
        // topoSort
        // Store Indegree of the graph
        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        
        // store Zero degree node in queue because they should appear first
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] ==0) q.push(i);
        }
        
        // store linear order that [Ai,Bi] Bi take first before taking Ai
        int cnt=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        return cnt == numCourses;
  
    }
};