class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool>tab_l(9,false);
        vector<bool>tab_c(9,false);

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                
                if(board[i][j] == '.') continue;

                int n = board[i][j] - '1';

                if(tab_l[n]) return false;

                tab_l[n] = true;
                


            }
            fill(tab_l.begin(), tab_l.end(), false);
        }

        for(int j=0;j<9;j++){
            for(int i=0;i<9;i++){
                if(board[i][j] == '.') continue;

                int n = board[i][j] - '1';

                if(tab_c[n]) return false;

                tab_c[n] = true;
            }
            fill(tab_c.begin(), tab_c.end(), false);

        }

        for(int k = 0; k < 9; k++){

            vector<bool> tab_s(9, false);
            int start_row = (k / 3) * 3;
            int start_col = (k % 3) * 3;
            
            for (int i = 0; i < 3; i++){
                for(int j=0; j < 3; j++){
                          
                    if(board[i + start_row][j + start_col] == '.') continue;

                    int n = board[i + start_row][j + start_col] - '1';

                    if(tab_s[n]) return false;

                    tab_s[n] = true;


                }
            }

        }

        return true;         

        
    }
};
