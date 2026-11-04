class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefix(height.size(), 0);
        vector<int> suffix(height.size(), 0);

        int maxHeight = 0;
        for(int i = 0; i < height.size(); i++){
            maxHeight = max(maxHeight, height[i]);
            prefix[i] = maxHeight;
        }

        maxHeight = 0;

        for(int i= height.size()-1; i > -1 ; i--){
            maxHeight = max(maxHeight, height[i]);
            suffix[i] = maxHeight;
        }

        int sum = 0;
        for(int i = 0; i < height.size(); i++){
            sum += min(prefix[i], suffix[i]) - height[i];
        }

        return sum;



    }
};
