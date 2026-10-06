class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> el(nums.begin(), nums.end());

        int best = 0;
        for(int a: nums){
            if (el.count(a-1)) continue;

            int count = 0;
            while(el.count(a)){
                count++;
                a++;
            }  

            if (best<count) best = count;
        }

        return best;
    }
};