#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &board, int value)
{
    int n = board.size();

    for (int i = 0; i < n; i++)
    {
        // row check
        if (board[row][i] == value)
            return false;

        // col check
        if (board[i][col] == value)
            return false;

        // 3*3 box check
        if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == value)
            return false;
    }

    return true;
}

bool solve(vector<vector<int>> &board)
{
    int n = board.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // check for empty cell
            if (board[i][j] == 0)
            {
                // try to fill with values ranging from 1 to 9
                for (int val = 1; val <= 9; val++)
                {
                    // check for safety
                    if (isSafe(i, j, board, val))
                    {
                        // insert
                        board[i][j] = val;
                        // recursion sambal lega
                        bool remainingBoardSolution = solve(board);
                        if (remainingBoardSolution == true)
                        {
                            return true;
                        }
                        else
                        {
                            // backtrack
                            board[i][j] = 0;
                        }
                    }
                }
                // if 1 se 9 tak koi bhi value se solution
                // nahi nikla ,current cell pr,
                // that means piche kahin pr galti h ,
                // go back by returning false
                return false;
            }
        }
    }
    // all cells filled
    cout<<"Solution found"<<endl;
    return true;
}

void solveSudoku(vector<vector<int>> &board)
{
    cout << solve(board);
}

int main()
{

    vector<vector<int>> board = {{1, 0, 0, 0, 0, 0, 0, 0, 3},
                                 {0, 0, 7, 2, 6, 0, 4, 8, 0},
                                 {4, 0, 0, 9, 3, 5, 0, 0, 6},
                                 {0, 3, 0, 4, 8, 0, 2, 0, 0},
                                 {0, 4, 1, 6, 0, 9, 3, 0, 0},
                                 {0, 0, 6, 0, 0, 0, 8, 9, 0},
                                 {5, 7, 8, 0, 4, 0, 0, 0, 2},
                                 {0, 0, 0, 3, 0, 0, 0, 7, 0},
                                 {2, 0, 0, 0, 0, 0, 0, 0, 5}};

    solveSudoku(board);

    return 0;
}
