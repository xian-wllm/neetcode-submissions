class Solution {
public:
    bool dfs_with_cycle(int node, vector<vector<int>>& adj, vector<int>& state){
        if(state[node] == 1){
            return true;
        }

        if(state[node] == 2){
            return false;
        }

        state[node] = 1;

        for(int next_node : adj[node]){
            if(dfs_with_cycle(next_node, adj, state)){
                return true;
            }
        }

        state[node] = 2;

        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);

        for(const auto& couple : prerequisites){
            
            int i = couple[1];
            int j = couple[0];

            adj[i].push_back(j);

        }


        vector<int> state(numCourses, 0);

        for(int i = 0; i < numCourses; i++){
            
            if(dfs_with_cycle(i, adj, state)){
                return false;
            }
        }
        return true;

    }
};
