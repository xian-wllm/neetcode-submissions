class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        
        while(left <= right){
            
            int mid = left + (right - left) / 2;
            long long total_hours = 0;
            
            for(int i = 0; i < piles.size(); i++){
                long long hour = (piles[i] + (long long)mid - 1) / mid;
                total_hours += hour;
            }
            
            if(total_hours <= h){
                right = mid - 1;
            }else{
                left = mid + 1; 
            }

        }

        return left;


    }
};
