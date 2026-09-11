class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int n : nums) {
            freq[n]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);

        for (auto& [number, count] : freq) {
            bucket[count].push_back(number);
        }

        vector<int> result;

        for (int count = nums.size(); count >= 1; count--) {
            for (int number : bucket[count]) {
                result.push_back(number);

                if (result.size() == k) {
                    return result;
                }
            }
        }

        return result;
    }
};