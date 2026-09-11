class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mapa;
        for(int i=0; i<nums.size();i++){
            mapa[nums[i]]++;
        }

        vector<pair<int, int>> v;

        for (auto e : mapa) {
            v.push_back(e);
        }

        sort(v.begin(), v.end(), [](auto a, auto b) {
            return a.second > b.second;});

        vector<int> final_list;
        for(int i=0; i<k;i++){
            final_list.push_back(v[i].first);
        }
        
        return final_list;
        
    }
};
