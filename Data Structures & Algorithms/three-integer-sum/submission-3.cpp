class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++){
            
            int left = i + 1;
            int right = nums.size() - 1;
            
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }

            while(left < right){
                int sum = nums[left] + nums[right];
                if(sum == -nums[i]){
                    res.push_back({nums[left], nums[i] , nums[right]});
                    left++;
                    right--;

                    while(left < right && nums[left] == nums[left-1]){
                        left++;
                    }

                    while(left < right && nums[right] == nums[right+1]){
                        right--;
                    }

                }else if(sum < -nums[i]){
                    left++;
                
                }else{
                    right--;
                    }
                    
            }
        }
        return res;
        }
};
