class Solution {
public:
    // main rules are skip '.' user map in square ues row col then r and c so like row + r and col + c
    bool chrow(vector<vector<char>>& board){

    unordered_map<char, int> mp;

        for(int row = 0; row < board.size(); row++){
            for(int col = 0; col < board[row].size(); col++){
                if(board[row][col] == '.') continue;
                mp[board[row][col]]++;
            }
            for(auto it = mp.begin(); it != mp.end(); it++){
                if(it->second > 1){
                    return false;
                }
            }
            mp.clear();

        }
        return true;
    }
    bool chcol(vector<vector<char>>& board){
    unordered_map<char, int> mp;

        for(int col = 0; col < board.size(); col++){
            for(int row = 0; row < board[row].size(); row++){
                if(board[row][col] == '.') continue;

                mp[board[row][col]]++;
            }

            for(auto it = mp.begin(); it != mp.end(); it++){
                if(it->second > 1){
                    return false;
                }
            }
            mp.clear();

        }
        return true;
    }
    bool chsq(vector<vector<char>>& board){
        unordered_map<char, int> mp;
        for(int row = 0; row < 9  ; row += 3){
            for(int col = 0; col < 9; col += 3){

                for(int r = 0; r < 3; r++){
                    for(int c = 0; c < 3; c++){
                        if(board[row+r][col+c] == '.') continue;
                        mp[board[row+r][col+c]]++;
                    }
                }

                for(auto it = mp.begin(); it != mp.end(); it++){
                    if(it->second > 1) return false;
                }
                mp.clear(); // Clear the map for the next box!
            }
                 
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return chrow(board) && chcol(board) && chsq(board);
    }
