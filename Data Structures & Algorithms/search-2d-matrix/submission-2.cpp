class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int a = 0;
        int col = matrix[0].size();
        int b = matrix.size() * col - 1;

        while (a <= b) {

            int mid = a + (b - a) / 2;

            int i = mid / col;
            int j = mid % col;

            if (matrix[i][j] == target) {
                return true;
            }
            else if (matrix[i][j] < target) {
                a = mid + 1;
            }
            else {
                b = mid - 1;
            }
        }

        return false;
    }
};