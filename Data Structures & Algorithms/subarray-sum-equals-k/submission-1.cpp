class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int count = 0;
        int currentSum = 0;
        unordered_map<int,int> prefixCount;

        prefixCount[0] = 1;

        for(int i = 0; i < nums.size(); i++){
            currentSum += nums[i];

            count += prefixCount[currentSum - k];

            prefixCount[currentSum]++;


        } 

        return count;
    }
};