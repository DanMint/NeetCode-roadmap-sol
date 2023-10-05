class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::pair<int, int> boardSize = {9, 9};

        for(int i = 0; i < board.size(); i ++) {
            for (int j = 0; j < board[i].size(); j ++) {
                char currentCell = board[i][j];
                if (currentCell == '.')
                    continue;

                /// here we check all elements on the x axis
                for (int a = 0; a < board.size(); a ++) {
                    if (a == i)
                        continue;
                    if (currentCell == board[a][j])
                        return false;
                }

                /// here we check all elements on y axis
                for (int k = 0; k < board.size(); k ++) {
                    if (k == j)
                        continue;
                    if (currentCell == board[i][k])
                        return false;
                }

                if (!threeXthreeChecker(board, i, j, currentCell))
                    return false;
            }
        }

        return true;
    }

    bool threeXthreeChecker (const std::vector<std::vector<char>> &board, const int &vectorNum, const int &posInVector, const char &val) {
        std::vector<std::pair<int, int>> toCheck;
        
        int vecPos = vectorNum / 3;
        int posInVec = posInVector / 3;
        
        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j++) {
                if (i == vectorNum && j == posInVector)
                    continue;
                else if (i / 3 == vecPos && j / 3 == posInVec)
                    toCheck.push_back({i, j});
            }
        }
        
        for (const auto &el : toCheck) {
            if (board[el.first][el.second] == val)
                return false;
        }
        return true;
    }
};
