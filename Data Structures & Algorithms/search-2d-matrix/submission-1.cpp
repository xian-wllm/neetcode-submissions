
int convert_2d_to_1d(int i, int j, int& col){
    return i * col + j;
}

pair<int, int> convert_1d_to_2d(int n, int& col){
    int i = n / col;
    int j = n % col;

    return {i,j};
}

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int a = 0;
        int b = matrix[a].size() * matrix.size() - 1;
        int col = matrix[0].size();

        while(a <= b){
            int mid = a + (b - a) / 2;
            pair<int, int> mid_2d = convert_1d_to_2d(mid, col); 
            if(matrix[mid_2d.first][mid_2d.second] == target){
                return true;
            }
            else if(matrix[mid_2d.first][mid_2d.second] < target){
                a = mid + 1;
            }
            else{
                b = mid - 1;
            }            
        }

        return false;
    }
};
