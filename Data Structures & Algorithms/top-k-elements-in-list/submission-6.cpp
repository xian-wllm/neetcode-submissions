class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> freq;
        for(int n : nums){
            freq[n]++;
        }

        priority_queue<pair<int,int>> pq;

        for(auto [key, val] : freq){
            pq.push({val, key});
        }

        vector<int> res;
        for(int i = 0; i < k; i++){
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;

    }
};
