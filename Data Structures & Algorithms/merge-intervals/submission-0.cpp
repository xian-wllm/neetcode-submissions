class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), 
            [](const vector<int>& intervalA, const vector<int>& intervalB){
                return intervalA[0] < intervalB[0];
        });  

        vector<vector<int>> results;
        for(int i = 0; i < intervals.size(); i++){
            if(results.size() == 0){
                results.push_back(intervals[i]);
                continue;
            }
            
            auto last_interval = results.back();
            if(intervals[i][0] <= last_interval[1]){
                vector<int> merged_interval = {min(last_interval[0], intervals[i][0]), 
                                max(last_interval[1], intervals[i][1])};
                results.pop_back();
                results.push_back(merged_interval);
            }else{
                results.push_back(intervals[i]);
            }

        }
        
        return results;

    }
};
