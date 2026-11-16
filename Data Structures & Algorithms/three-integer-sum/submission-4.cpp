class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        set<vector<int>> uniqueTriplets;

        for (int i = 0; i < nums.size(); i++) {

            int c = nums[i];
            unordered_set<int> seen;

            for (int j = i + 1; j < nums.size(); j++) {

                int a = nums[j];
                int target = -a - c;

                if (seen.count(target)) {
                    vector<int> triplet = {c, a, target};

                    sort(triplet.begin(), triplet.end());

                    uniqueTriplets.insert(triplet);
                }

                seen.insert(a);
            }
        }

        return vector<vector<int>>(
            uniqueTriplets.begin(),
            uniqueTriplets.end()
        );
    }
};