class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<int>> strs_idx;
        
        for(int i=0; i<strs.size(); i++){
            string sorted = strs[i];
            sort(sorted.begin(), sorted.end());
            strs_idx[sorted].push_back(i);
        }

        vector<vector<string>> final_list;

        for(auto e: strs_idx){
            vector<string> current_list;
            for(auto idx: e.second){
                current_list.push_back(strs[idx]);
            }
            final_list.push_back(current_list);
        }

        return final_list;
        
    }
};
