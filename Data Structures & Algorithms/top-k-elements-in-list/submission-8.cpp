class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        for(int num : nums){
            mp[num]++;
        }

        vector<vector<int>> freqGrouped(nums.size() + 1);

        for(const auto& [value, freq] : mp){
            freqGrouped[freq].push_back(value);
        }

        vector<int> results;
        for(int i = freqGrouped.size() - 1; i >= 0; i--){
            for (int value : freqGrouped[i]) {
                results.push_back(value);

                if (results.size() == k) {
                    return results;
                }
            }
        }

        
        
    }
};
