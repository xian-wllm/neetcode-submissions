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
        int count = 0;
        for(int i = nums.size(); i > 0; i--){

            if(buckets[i].size() != 0){
                for(int n : buckets[i]){
                    results.push_back(n);
                    count++;

                    if(count == k){
                        return results;
                    }
                }
            }

        }
        


    }
};
