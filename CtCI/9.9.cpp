#include <iostream>
#include <vector>
#include <cstdlib> // abs
#include <set>

std::vector< std::vector< std::vector<bool> > > placeQueen(int row, int col, std::vector< std::vector<bool> > board_queen, std::vector< std::vector<bool> > board_free)
{
    std::vector< std::vector< std::vector<bool> > > new_boards;

    board_queen[row][col] = true;
    new_boards.push_back(board_queen);

    int num_rows = board_queen.size();
    int num_cols = board_queen[0].size();
    for (int i_row = 0; i_row < num_rows; ++i_row)
    {
        for (int i_col = 0; i_col < num_cols; ++i_col)
        {
            if (i_row == row || i_col == col || abs(row-i_row) == abs(col-i_col))
            {
                board_free[i_row][i_col] = false;
            }
        }
    }
    new_boards.push_back(board_free);

    return new_boards;
}

void printBoard(const std::vector< std::vector<bool> > &board_queen)
{
    int num_rows = board_queen.size();
    int num_cols = board_queen[0].size();
    for (int row = 0; row < num_rows; ++row)
    {
        for (int col = 0; col < num_cols; ++col)
        {
            if (board_queen[row][col])
            {
                std::cout << "X ";
            }
            else
            {
                std::cout << "O ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "########################" << std::endl << std::endl;
}

void printAllWaysUtil(int num_queens, std::vector< std::vector<bool> > &board_queen, std::vector< std::vector<bool> > &board_free, std::set< std::vector< std::vector<bool> > > &queen_boards_set)
{
    int num_rows = board_queen.size();
    int num_cols = board_queen[0].size();

    if (num_queens == 1)
    {
        for (int row = 0; row < num_rows; ++row)
        {
            for (int col = 0; col < num_cols; ++col)
            {
                if (board_free[row][col])
                {
                    std::vector< std::vector< std::vector<bool> > > new_boards = placeQueen(row, col, board_queen, board_free);
                    std::vector< std::vector<bool> > new_board_queen = new_boards[0];
                    queen_boards_set.insert(new_board_queen);
                }
            }
        }

        return;
    }

    for (int row = 0; row < num_rows; ++row)
    {
        for (int col = 0; col < num_cols; ++col)
        {
            if (board_free[row][col])
            {
                std::vector< std::vector< std::vector<bool> > > new_boards = placeQueen(row, col, board_queen, board_free);
                std::vector< std::vector<bool> > new_board_queen = new_boards[0];
                std::vector< std::vector<bool> > new_board_free = new_boards[1];
                printAllWaysUtil(num_queens-1, new_board_queen, new_board_free, queen_boards_set);
            }
        }
    }
}

void printAllWays(int n)
{
    std::vector< std::vector<bool> > board_free(n , std::vector<bool>(n, true));
    std::vector< std::vector<bool> > board_queen(n , std::vector<bool>(n, false));
    std::set< std::vector< std::vector<bool> > > queen_boards_set;

    printAllWaysUtil(n, board_queen, board_free, queen_boards_set);

    for (auto i = queen_boards_set.begin(); i != queen_boards_set.end(); ++i)
    {
        printBoard(*i);
    }

    std::cout << "n = " << n << ", number of boards: " << queen_boards_set.size() << std::endl;
}

int main()
{
    printAllWays(8);

    return 0;
}
