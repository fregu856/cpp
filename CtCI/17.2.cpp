#include <iostream>
#include <vector>

// NOTE! This code can be made MUCH simpler! My algorithm is actually kind of silly...

void printGame(std::vector< std::vector<int> > &game)
{
    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            if (game[row][col] == 0)
            {
                std::cout << "- ";
            }
            else if (game[row][col] == -1)
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
}

bool isGameWonUtil(std::vector< std::vector<int> > &game, int value, int row, int col, int dir)
{
    switch (dir)
    {
        case 0:
            return (row-1 >= 0 && col-1 >= 0 && (game[row-1][col-1] == value));
        case 1:
            return (row-1 >= 0 && (game[row-1][col] == value));
        case 2:
            return (row-1 >= 0 && col+1 < 3 && (game[row-1][col+1] == value));
        case 3:
            return (col+1 < 3 && (game[row][col+1] == value));
        case 4:
            return (row+1 < 3 && col+1 < 3 && (game[row+1][col+1] == value));
        case 5:
            return (row+1 < 3 && (game[row+1][col] == value));
        case 6:
            return (row+1 < 3 && col-1 >= 0 && (game[row+1][col-1] == value));
        case 7:
            return (col-1 >= 0 && (game[row][col-1] == value));
    }
}

bool isGameWon(std::vector< std::vector<int> > &game, int value)
{
    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            if (game[row][col] == value)
            {
                if (row-1 >= 0 && col-1 >= 0 && (game[row-1][col-1] == value))
                {
                    if (isGameWonUtil(game, value, row-1, col-1, 0))
                    {
                        return true;
                    }
                }

                if (row-1 >= 0 && (game[row-1][col] == value))
                {
                    if (isGameWonUtil(game, value, row-1, col, 1))
                    {
                        return true;
                    }
                }

                if (row-1 >= 0 && col+1 < 3 && (game[row-1][col+1] == value))
                {
                    if (isGameWonUtil(game, value, row-1, col+1, 2))
                    {
                        return true;
                    }
                }

                if (col+1 < 3 && (game[row][col+1] == value))
                {
                    if (isGameWonUtil(game, value, row, col+1, 3))
                    {
                        return true;
                    }
                }

                if (row+1 < 3 && col+1 < 3 && (game[row+1][col+1] == value))
                {
                    if (isGameWonUtil(game, value, row+1, col+1, 4))
                    {
                        return true;
                    }
                }

                if (row+1 < 3 && (game[row+1][col] == value))
                {
                    if (isGameWonUtil(game, value, row+1, col, 5))
                    {
                        return true;
                    }
                }

                if (row+1 < 3 && col-1 >= 0 && (game[row+1][col-1] == value))
                {
                    if (isGameWonUtil(game, value, row+1, col-1, 6))
                    {
                        return true;
                    }
                }

                if (col-1 >= 0 && (game[row][col-1] == value))
                {
                    if (isGameWonUtil(game, value, row, col-1, 7))
                    {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

bool isGameWon(std::vector< std::vector<int> > &game)
{
    return isGameWon(game, -1) || isGameWon(game, 1);
}

int main()
{
    std::vector< std::vector<int> > game = {{-1, -1, 0},
                                            {1, -1, 1},
                                            {1, -1, 1}};
    printGame(game);

    if (isGameWon(game))
    {
        std::cout << "The game has been won!" << std::endl;
    }
    else
    {
        std::cout << "The game has NOT been won!" << std::endl;
    }

    return 0;
}
