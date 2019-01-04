class Solution:
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        row = [{}, {}, {}, {}, {}, {}, {}, {}, {}]
        col = [{}, {}, {}, {}, {}, {}, {}, {}, {}]
        palace = [{}, {}, {}, {}, {}, {}, {}, {}, {}]
        for i in range(9):
            for j in range(9):
                cell = (3*(i//3) + j//3)
                num = board[i][j]
                if num != '.':
                    if (num not in row[i]) and (num not in col[j]) and (num not in palace[cell]):
                        row[i][num] = 1
                        col[j][num] = 1
                        palace[cell][num] = 1
                    else:
                        return False
        return True