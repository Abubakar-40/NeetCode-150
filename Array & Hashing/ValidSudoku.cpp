//https://neetcode.io/problems/valid-sudoku?list=neetcode150


// Time Complexity : O(1)
// Space Complexity : O(1)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> box[9];

        for(int i = 0; i< 9; i++){
            for(int j = 0; j<9; j++){
                char n = board[i][j];
                if(n == '.'){
                    continue;
                }
                int boxIdx = (i/3) * 3 +(j/3);

                if(rows[i].count(n)){
                    return false;
                }
                if(cols[j].count(n)){
                    return false;
                }
                if(box[boxIdx].count(n)){
                    return false;
                }
                rows[i].insert(n);
                cols[j].insert(n);
                box[boxIdx].insert(n);

            }
            
        }
        return true;
    }
};
