class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> el;
        for(int a: nums){
            el.insert(a);
        }
        int count;
        int best = 0;
        for(int a: nums){
            if (el.contains(a-1)) continue;

            count = 0;
            while(el.contains(a)){
                count++;
                a++;
            }  

            if (best<count) best = count;
        }

        return best;
    }
};