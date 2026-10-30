class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> dict;

        for(int a : nums){
            if(dict.contains(a)){
                return true ;
            }else{
                dict[a] = true; 
            }
        }
        
        return false;
    }
};