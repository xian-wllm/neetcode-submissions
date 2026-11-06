class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] < nums[right]){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        

        int left_for_left = 0;
        int right_for_left = left;
        
        while(left_for_left <= right_for_left){
            int mid = left_for_left + (right_for_left - left_for_left) / 2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                left_for_left = mid + 1;
            }else{
                right_for_left = mid - 1;
            }
        }
        
        int left_for_right = left;
        int right_for_right = nums.size() - 1;

        while(left_for_right <= right_for_right){
            int mid = left_for_right + (right_for_right - left_for_right) / 2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                left_for_right = mid + 1;
            }else{
                right_for_right = mid - 1;
            }
        }

        return -1;

    }
};
