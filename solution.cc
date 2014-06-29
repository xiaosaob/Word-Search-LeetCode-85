// Given a 2D board and a word, find if the word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

// For example,
// Given board =

// [
//   ["ABCE"],
//   ["SFCS"],
//   ["ADEE"]
// ]
// word = "ABCCED", -> returns true,
// word = "SEE", -> returns true,
// word = "ABCB", -> returns false.

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if(!word.size()) return true;
        int m = board.size();
        if(!m) return false;
        int n = board[0].size();
        if(!n) return false;
        
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(board[i][j] == word[0]) 
                    if(helper(board,i,j,word,1))
                        return true;
        return false;
    }
    
    bool helper(vector<vector<char> > &board, int i, int j, string word, int idx) {
        if(idx == word.size()) return true;
        
        char oldc = board[i][j];
        board[i][j] = '#';
        bool result = false;
        if(i-1 >= 0 && board[i-1][j] == word[idx] && helper(board,i-1,j,word,idx+1)) result = true;
        else if(i+1 < board.size() && board[i+1][j] == word[idx] && helper(board,i+1,j,word,idx+1)) result = true;
        else if(j-1 >= 0 && board[i][j-1] == word[idx] && helper(board,i,j-1,word,idx+1)) result = true;
        else if(j+1 < board[0].size() && board[i][j+1] == word[idx] && helper(board,i,j+1,word,idx+1)) result = true;
        board[i][j] = oldc;
        return result;
    }
};
