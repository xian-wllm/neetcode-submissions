class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> freq;
        for(int n : nums){
            freq[n]++;
        }

        vector<vector<int>> buckets(nums.size()+1);

        for(const auto& [key, value] : freq){
            buckets[value].push_back(key);
        }

        vector<int> results;
        bool valid = false;
        for(int i = nums.size(); i > 0; i--){

            if(valid){
                break;
            }

            for(int n : buckets[i]){
                results.push_back(n);

                if(results.size() == k){
                    valid = true;
                }
            }
        }

        return results;
        
    }
};
