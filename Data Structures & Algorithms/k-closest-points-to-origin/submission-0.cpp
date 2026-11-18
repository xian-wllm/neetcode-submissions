class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        int x0 = 0;
        int y0 = 0;
        priority_queue<pair<int,vector<int>>> pq;
        vector<vector<int>> results;

        for(int i = 0; i < points.size(); i++){
            int x1 = points[i][0];
            int y1 = points[i][1];

            int distSquared = x1 * x1  + y1 * y1; //since x0 and yo are 0
            pq.push({distSquared, {x1, y1}});

            if(pq.size() > k){
                pq.pop();
            }

        }

        while(!pq.empty()){
            auto [dist, point] = pq.top();
            pq.pop();

            results.push_back({point[0], point[1]});
        }
        
        return results;
    }
};
