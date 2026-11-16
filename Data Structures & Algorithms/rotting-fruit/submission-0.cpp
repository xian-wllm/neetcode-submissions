class Solution {
public:


int orangesRotting(vector<vector<int>>& grid) {
    
    queue<pair<int,int>> q;
    
    int min = -1;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] == 2){
                q.push({i, j});
                
            }
        }
    }

    int count = -1;
    while(!q.empty()){

        int levelSize = q.size();

        for(int k = 0; k < levelSize; k++){
            auto [i, j] = q.front();
            q.pop();


            // Bas
            if (i + 1 < grid.size() && grid[i + 1][j] == 1) {
                grid[i + 1][j] = 2;
                q.push({i + 1, j});
            }

            // Haut
            if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                grid[i - 1][j] = 2;
                q.push({i - 1, j});
            }

            // Droite
            if (j + 1 < grid[0].size() && grid[i][j + 1] == 1) {
                grid[i][j + 1] = 2;
                q.push({i, j + 1});
            }

            // Gauche
            if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                grid[i][j - 1] = 2;
                q.push({i, j - 1});
            }
        }    

        count++;    
    }

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
        }
    }

    return max(0, count);

    return count;

}
};
