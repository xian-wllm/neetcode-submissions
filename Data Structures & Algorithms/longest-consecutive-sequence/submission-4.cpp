class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen;

        for(int n : nums){
            seen.insert(n);
        } 

        int result = 0;
        for(int i = 0; i < nums.size(); i++){
            
            if(seen.count(nums[i] - 1)){
                continue;
            }

            int val = nums[i];
            int count = 1;
            while(seen.count(val+1)){
                val++;
                count++;
            }

            result = max(result, count);
        }

        return result;
    }
};
